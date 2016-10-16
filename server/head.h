#ifndef _HEAD_H
#define _HEAD_H

#include <mysql/mysql.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/mman.h>
#include <signal.h>
#include <ctype.h>
#include <time.h>

#define N 10
#define DOWNLOAD "000.avi"
#define LEVEL_LEN 100 //目录级别，可以到100级
#define MY_NAME_LEN 100 //目录名字,可以长100
//生成密文时，salt最长为16，存储的字符串设为18，生成密文最长为106，存储设为108，真正密文为87.
//char *cmd=XXarguments;
#define THE_SERVER_PATH_LEN strlen("/home/t520/linux/1") //char pwd[100]="/home/t520/linux/1"; ;
typedef struct{
    int len;//发送的buf长度
    char buf[1000];
}data;

typedef struct que{
    struct sockaddr_in client_info;//与fd相对应的客户端信息,ip和port
    int fd;//已连接的客户端
    struct que* next;
}qnode,*pqnode;

typedef struct{
    pqnode phead,ptail;//队列头尾指针,用于取fd和相应信息
    pthread_mutex_t mutex;//队列锁
    int qsize;//队列cur_num
}q_info,*pq_info;

typedef void*(*pth_routine)(void*);

typedef struct{
    pthread_t *pth;//全部子线程的地址，申请空间为子线程数
    int p_num;//子线程数
    pthread_cond_t cond;//等待条件,取任务等待
    q_info que;//队列信息,头尾指针,队列锁
    int q_num;//listen num
    pth_routine get_cmd;//任务函数
    char flag;//是否初始化或清空
    struct sockaddr_in * the_client_addr_info;//客户端信息,申请空间为listen num
}pth_info,*ppth_info;

typedef struct login_table{
    int id;
    char user_name[20];
    char user_pwd[100];
    struct login_table*next;
}login_table,*p_login_table;//用户名(唯一),密文

typedef struct syslog_table{
    int id;
    char data[20];
    char cmd[100];
    char the_result[100];
    char user_name[20];
    struct syslog_table*next;
}syslog_table,*p_syslog_table;//时间戳,cmd,用户名(唯一性)

void* pth_get_cmd(void*p1);//任务函数
int pthread_pool_init(ppth_info p,int pn,int qn);//初始化线程池
int pthread_pool_create(ppth_info p);//创建线程池
int queue_add(pq_info p,pqnode q);//增加任务队列
int queue_del(pq_info p,pqnode* q1);//删除任务队列

int gets_cmd(char*p);
int send_n(int sfd,char*p,int len);
int recv_n(int sfd,char*p,int len);
int run_cmd(int i,int sfd,char*cmd,char*pwd);

int recv_file(int sfd,data *d);
int send_file(int sfd,data *d);

int run_cmd_cd(int sfd,char *cmd,char*pwd);
int run_cmd_ls(int sfd,char *cmd,char*pwd);
int run_cmd_pwd(int sfd,char *cmd,char*pwd);
int run_cmd_gets(int sfd,char *cmd,char*pwd);
int run_cmd_puts(int sfd,char *cmd,char*pwd);
int run_cmd_mkdir(int sfd,char *cmd,char*pwd);
int run_cmd_remove(int sfd,char *cmd,char*pwd);

int send_str(int sfd,char * str);
int strcat_pwd(char *cmd,char*pwd);
int syslog_write(char*cmd);
int insert_mysql_syslog(char*data_info,char*cmd);
int the_file_position(char*buf,long *file_len);
int send_file_use_mmap(int sfd,int fd,long file_len,long the_send_len,long the_file_total_len);

int insert_mysql_login(char*user_name,char*user_pwd,char*user_salt);
int strcat_the_mysql_cmd(char *query_str,char*cmd,...);//参数必须以0结尾，或者以NULL；且cmd参数不能为NULL
int user_login(char*client_info_sin_addr,int fd,char*pwd);
int select_mysql_login(char*user_name,char*user_pwd);
void handler(int num);
int signal_catch();
int select_mysql_login_salt(char*user_name,char*user_salt);
int salt_create_rand(char *my_salt,int my_salt_len);//my_salt_len有效位为16位，所以my_salt_len<=16;my_salt至少分配18个字节
#endif

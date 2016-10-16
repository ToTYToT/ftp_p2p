#ifndef _HEAD_H
#define _HEAD_H
#define _XOPEN_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>
#include <fcntl.h>
#define CMD_LEN 50//cmd格式为XX+filename(arguments)
#define CMD_NUM 9
typedef struct{
    int len;
    char buf[1000];
}data;
int connect_server(int *sfd,char*s_addr,char*port);
int gets_cmd(char *cmd_buf);
int analysis_cmd(char *cmd_buf);
int run_cmd(int cmd_num,int sfd,char* cmd_buf);
int send_recv_printf(int sfd,char * cmd_buf);//发送一次，接受结束标志为d.len=0，打印
int recv_file(int sfd,char *cmd_buf);
int send_file(int sfd,char *cmd_buf);
int send_n(int sfd,char*p,int len);
int recv_n(int sfd,char*p,int len);
int recv_broken_file(int sfd,int fd,char* cmd_buf);
char* the_ltoa(long num,char*str);
int client_user_login(int sfd);
int recv_printf(int sfd);
int	recv_str(int sfd,char *str);
int	salt_password(char*user_salt,char*buf);
#endif
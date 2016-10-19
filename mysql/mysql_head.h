#ifndef _MYSQL_HEAD_H
#define _MYSQL_HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysql.h"
#include "errmsg.h"
#include "mysqld_error.h"


typedef struct mysql_connection_info{
    char host[20];
    char user[20];
    char password[20];
    char database[20];
    struct mysql_connection_info * next;
}mysql_connection_info,*mysql_connection_info_p;

typedef struct mysql_the_user_login_info{
    int id;
    char user_name[21];
    char user_pwd[109];
    char user_salt[101];
    char pwd[101];
    struct mysql_the_user_login_info * next;
}mysql_the_user_login_info,*mysql_the_user_login_info_p;

typedef struct mysql_the_user_syslog_info{
    int id;
    char data[21];
    char cmd[101];
    char the_result[101];
    char user_name[21];
    struct mysql_the_user_syslog_info* next;
}mysql_the_user_syslog_info,*mysql_the_user_syslog_info_p;

//里面申请空间且赋值结构体指针
int mysql_connocet(MYSQL *conn,mysql_connection_info_p con_p);
int mysql_login_set_info_values(mysql_the_user_login_info_p *user_info,int id,char *user_name,char *user_pwd,char *user_salt,char *pwd)//里面赋值结构体指针
int mysql_login_delete(MYSQL *conn,mysql_the_user_login_info_p info_p);
int mysql_login_insert(MYSQL *conn,mysql_the_user_login_info_p info_p);
int mysql_login_update(MYSQL *conn,mysql_the_user_login_info_p info_p);
int mysql_login_select(MYSQL *conn,mysql_the_user_login_info_p info_p);
int mysql_login_select_result_link(MYSQL *conn,mysql_the_user_login_info_p* login_info_ptail,int *the_info_num,char *mysql_query_cmd);

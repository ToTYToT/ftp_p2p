#include "head.h"

int insert_mysql_syslog(char*data_info,char*cmd)
{
    MYSQL           mysql;
    MYSQL_RES       *res = NULL;
    MYSQL_ROW       row;
    int             rc, i, fields;
    int             rows;
    if (NULL == mysql_init(&mysql)) {
        printf("mysql_init(): %s\n", mysql_error(&mysql));
        return -1;
    }
    if (NULL == mysql_real_connect(&mysql,"localhost","root","t520","the_user",0,NULL,0)) {
        printf("mysql_real_connect(): %s\n", mysql_error(&mysql));
        return -1;
    }
    //printf("1. Connected MySQL successful! \n");
    char query_str[100]= "insert into syslog (data,cmd) values (";
    strcat_the_mysql_cmd(query_str,data_info,cmd,NULL);
    rc = mysql_real_query(&mysql, query_str, strlen(query_str));
    if (0 != rc) {
        printf("mysql_real_query(): %s\n", mysql_error(&mysql));
        return -1;
    }
    mysql_close(&mysql);
    return 0;
}

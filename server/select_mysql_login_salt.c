#include "head.h"

int select_mysql_login_salt(char*user_name,char*user_salt)
{
    MYSQL           mysql;
    MYSQL_RES       *res = NULL;
    MYSQL_ROW       row;
    int             rc, i, fields;
    my_ulonglong    the_result_row_num;
    MYSQL_RES *mysql_store_result(MYSQL *connection);
    if (NULL == mysql_init(&mysql)) {
        printf("mysql_init(): %s\n", mysql_error(&mysql));
        return -1;
    }
    if (NULL == mysql_real_connect(&mysql,"localhost","root","t520","the_user",0,NULL,0)){
        //printf("mysql_real_connect(): %s\n", mysql_error(&mysql));
        return -1;
    }
    char query_str[100]={0};
    sprintf(query_str,"%s%s%s","select * from login where user_name='",user_name,"\'");
    rc = mysql_real_query(&mysql, query_str, strlen(query_str));
    if (0 != rc) {
        //printf("mysql_real_query(): %s\n", mysql_error(&mysql));
        mysql_close(&mysql);
        return -1;
    }
    res=mysql_use_result(&mysql);
    if(NULL==(row=mysql_fetch_row(res))){
        mysql_close(&mysql);
        return -1;
    }
    strcpy(user_salt,row[3]);
    mysql_close(&mysql);
    return 0;
}

#include "head.h"

int insert_mysql_login(char*user_name,char*user_pwd,char*user_salt)
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
    if (NULL == mysql_real_connect(&mysql,
                "localhost",
                "root",
                "t520",
                "the_user",
                0,
                NULL,
                0)) {
        printf("mysql_real_connect(): %s\n", mysql_error(&mysql));
        return -1;
    }
    printf("1. Connected MySQL successful! \n");
    char query_str[100]= "insert into login (user_name,user_pwd,user_salt) values (";
   strcat_the_mysql_cmd(query_str,user_name,user_pwd,user_salt,NULL);
    rc = mysql_real_query(&mysql, query_str, strlen(query_str));
    if (0 != rc) {
        printf("mysql_real_query(): %s\n", mysql_error(&mysql));
        return -1;
        mysql_close(&mysql);
    return 0;
    }
}

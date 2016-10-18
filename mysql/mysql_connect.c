#include "mysql_head.h"

int mysql_connocet(MYSQL *conn,mysql_connection_info_p con_p)
{
    mysql_init(conn);
    if(mysql_real_connect(conn,con_p->host,con_p->user,con_p->password,con_p->database,0,NULL,0)){
      //  printf("Connection success!\n");
    } else {
        fprintf(stderr, "Connection failed!\n");
        if (mysql_errno(conn)) {
            fprintf(stderr, "Connection error %d: %s\n", mysql_errno(conn), mysql_error(conn));
        }
        return -1;
        //exit(EXIT_FAILURE);
    }
    return 0;
}

#include "mysql_head.h"

int mysql_login_delete(MYSQL *conn,mysql_the_user_login_info_p info_p)
{
    char tmp_query[360]={0};
    sprintf(tmp_query,"%s%d","delete from login  where id=",info_p->id);
    int res = mysql_real_query(&conn,tmp_query,strlen(tmp_query));
    if (!res) {
     //   printf("delete %lu rows\n", (unsigned long)mysql_affected_rows(&conn));
    } else {
        fprintf(stderr, "delete error %d: %s\n", mysql_errno(&conn), mysql_error(&conn));
        return -1;
    }
    return 0;
}

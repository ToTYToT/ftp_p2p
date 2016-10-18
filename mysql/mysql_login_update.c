#include "mysql_head.h"

int mysql_login_update(MYSQL *conn,mysql_the_user_login_info_p info_p)
{
    char tmp_query[360]={0};
    sprintf(tmp_query,"%s%s%s%s%s%s%s%s%s%d","update login set user_name='",
            info_p->user_name,"', user_pwd='",info_p->user_pwd,"', user_salt='",
            info_p->user_salt,"', user_pwd='",info_p->pwd,"' where id=",info_p->id);
    int res = mysql_real_query(&conn,tmp_query);
    if (!res) {
       // printf("Update %lu rows\n", (unsigned long)mysql_affected_rows(&conn));
    } else {
        fprintf(stderr, "Update error %d: %s\n", mysql_errno(&conn), mysql_error(&conn));
        return -1;
    }
    return 0;
}

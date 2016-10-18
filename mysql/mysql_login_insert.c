#include "mysql_head.h"

int mysql_login_insert(MYSQL *conn,mysql_the_user_login_info_p info_p)
{
    char tmp_query[360]={0};
    sprintf(tmp_query,"%s%s%s%s%s%s%s%s%s",
            "insert into login(user_name,user_pwd,user_salt,pwd) values('",
            info_p->user_name,"','",info_p->user_pwd,"','",
            info_p->user_salt,"','",info_p->pwd,"')");
    int res = mysql_real_query(&conn,tmp_query,strlen(tmp_query));
    if (!res) {
       // printf("Inserted %lu rows\n", (unsigned long)mysql_affected_rows(&conn));
    } else {
        fprintf(stderr, "Insert error %d: %s\n", mysql_errno(&conn), mysql_error(&conn));
        return -1;
    }
    return 0;
}

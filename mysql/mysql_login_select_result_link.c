#include "head.h"

int mysql_login_select_result_link(MYSQL *conn,mysql_the_user_login_info_p* login_info_ptail,int *the_info_num,char *mysql_query_cmd)
{
    *the_info_num=0;
    rc = mysql_real_query(conn, mysql_query_cmd, strlen(mysql_query_cmd));
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
    mysql_the_user_login_info_p new_login_info_p;
    mysql_login_set_info_values(&new_login_info_p,row[0],row[1],row[2],row[3],row[4]);
    (*login_info_ptail)->next=new_login_info_p;
    *login_info_ptail=new_login_info_p;
    *the_info_num=1;
    while(NULL!=(row=mysql_fetch_row(res))){
        //unsigned int the_result_filed_num=mysql_field_count(conn);
        mysql_the_user_login_info_p new_login_info_p;
        mysql_login_set_info_values(&new_login_info_p,row[0],row[1],row[2],row[3],row[4]);
        (*login_info_ptail)->next=new_login_info_p;
        *login_info_ptail=new_login_info_p;
        (*the_info_arr_num)++;
    }
    mysql_close(&mysql);
    return 0;
}

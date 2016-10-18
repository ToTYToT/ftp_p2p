#include "mysql_head.h"


int mysql_login_set_info_values(mysql_the_user_login_info_p *user_info,int id,char *user_name,char *user_pwd,char *user_salt,char *pwd)//里面赋值结构体指针
{
    *user_info=(mysql_the_user_login_info_p)calloc(1,sizeof(mysql_the_user_login_info));
    strcpy((*user_info)->user_name,user_name);
    strcpy((*user_info)->user_pwd,user_pwd);
    strcpy((*user_info)->user_salt,user_salt);
    strcpy((*user_info)->pwd,pwd);
    (*user_info)->id=id;
    return 0;
}

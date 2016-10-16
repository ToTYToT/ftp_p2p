#include "head.h"

int user_login(char*client_info_sin_addr,int sfd,char*pwd)
{
    send_str(sfd,"what's your name:");
    char user_name[100]={0};
    char user_salt[100]={0};
    recv_str(sfd,user_name);
    if(-1==select_mysql_login_salt(user_name,user_salt))strcpy(user_salt,"Hello");
    //printf("user_login user_name=%s520\n",user_name);
    send_str(sfd,"what's your password:");
    send_str(sfd,user_salt);
    char user_password[200]={0};
    recv_str(sfd,user_password);//zt7BTdkqHgLRU
    //printf("user_login %s520\n %s520\n",user_name,user_password);
    int the_login_result=select_mysql_login(user_name,user_password);
    if(0==the_login_result){
        send_str(sfd,"success");
    }else{
        send_str(sfd,"fail");
        return -1;
    }
    sprintf(pwd,"%s%s","/",user_name);
   // printf("%s\n",pwd);
    return 0;
}

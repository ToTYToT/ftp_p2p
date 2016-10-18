#include "head.h"

int run_cmd_mkdir(int sfd,char *cmd,char*pwd)
{
    strcat_pwd(cmd,pwd);
    int ret=mkdir(cmd,0664);
    if(-1==ret){
        send_str(sfd,"mkdir fail\n");
        send_str(sfd,"\0");
        return -1;
    }
    send_str(sfd,"mkdir success\n");
    send_str(sfd,"\0");
    return 0;
}

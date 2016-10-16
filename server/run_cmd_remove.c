#include "head.h"

int run_cmd_remove(int sfd,char *cmd,char*pwd)
{
    strcat_pwd(cmd,pwd);
    int ret=unlink(cmd);
    if(-1==ret){
        send_str(sfd,"remove fail\n");
        send_str(sfd,"\0");
        return -1;
    }
    send_str(sfd,"remove success\n");
    send_str(sfd,"\0");
    return 0;
}

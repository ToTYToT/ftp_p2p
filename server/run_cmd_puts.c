#include "head.h"

int run_cmd_puts(int sfd,char *cmd,char*pwd)
{
    strcat_pwd(cmd,pwd);
    data d;
    memset(&d,0,sizeof(d));
    strcpy(d.buf,cmd);
    d.len=strlen(d.buf);
    if(-1==recv_file(sfd,&d))return -1;
    return 0;
}

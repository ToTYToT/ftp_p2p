#include "head.h"

int run_cmd_gets(int sfd,char *cmd,char*pwd)
{
    strcat_pwd(cmd,pwd);
    data d;
    memset(&d,0,sizeof(d));
    strcpy(d.buf,cmd);
    d.len=strlen(d.buf);
    if(-1==send_file(sfd,&d))return -1;
}

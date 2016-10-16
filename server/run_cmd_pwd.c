#include "head.h"

int run_cmd_pwd(int sfd,char *cmd,char*pwd)
{
    send_str(sfd,pwd+18);
    send_str(sfd,"\0");
}

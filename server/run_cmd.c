#include "head.h"

int run_cmd(int i,int sfd,char*cmd,char*pwd)
{
	switch(i){
    case 0:
        run_cmd_cd(sfd,cmd,pwd);
        break;
    case 1:
        run_cmd_ls(sfd,cmd,pwd);
        break;
    case 2:
        run_cmd_pwd(sfd,cmd,pwd);
        break;
    case 3:
        if(-1==run_cmd_gets(sfd,cmd,pwd))return -1;
        break;
    case 4:
        if(-1==run_cmd_puts(sfd,cmd,pwd))return -1;
        break;
    case 5:
        run_cmd_mkdir(sfd,cmd,pwd);
        break;
    case 6:
        run_cmd_remove(sfd,cmd,pwd);
        break;
    default:
        break;
	}
	return 0;
}

#include "head.h"

int run_cmd(int cmd_num,int sfd,char* cmd_buf)
{
	//printf("run_cmd %s cmd_num=%d\n",cmd_buf,cmd_num);
	switch(cmd_num){
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			send_recv_printf(sfd,cmd_buf);//发命令，打印回执，回执全零时，结束
			break;
		case 6:
			if(-1==recv_file(sfd,cmd_buf))return -1;
			break;
		case 7:
			if(-1==send_file(sfd,cmd_buf))return -1;
			break;
	}
	return 1;
}

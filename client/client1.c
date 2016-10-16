#include "head.h"

int main(int argc, char*argv[])
{
    if(argc!=3){
        printf("argc addr port\n");
        return -1;
    }
	system("clear");
	int sfd;
	signal_catch();
	connect_server(&sfd,argv[1],argv[2]);//连接服务器,返回sfd,套接字描述符
	char cmd_buf[CMD_LEN];//cmd字符串
	int login_times;
	int user_login_result=0;
	for(login_times=0;login_times<5;login_times++){
		user_login_result=client_user_login(sfd);
		if(0==user_login_result){
                   break;
                }
	}
	if(5==login_times)return -1;
	int cmd_num;
	while(1){
		gets_cmd(cmd_buf);//获取字符串,有read,会阻塞,去除'\n'.
		cmd_num=analysis_cmd(cmd_buf);//修改cmd_buf格式为XX+filename,返回代码
		if(0==cmd_num) continue;
		if(8==cmd_num){
			send_str(sfd,"quit");
			break;
		}
		//if(-1==run_cmd(cmd_num,sfd,cmd_buf))break;//cmd_num为函数代码
		run_cmd(cmd_num,sfd,cmd_buf);//cmd_num为函数代码
	}
    close(sfd);
    return 0;
}

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
	connect_server(&sfd,argv[1],argv[2]);//���ӷ�����,����sfd,�׽���������
	char cmd_buf[CMD_LEN];//cmd�ַ���
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
		gets_cmd(cmd_buf);//��ȡ�ַ���,��read,������,ȥ��'\n'.
		cmd_num=analysis_cmd(cmd_buf);//�޸�cmd_buf��ʽΪXX+filename,���ش���
		if(0==cmd_num) continue;
		if(8==cmd_num){
			send_str(sfd,"quit");
			break;
		}
		//if(-1==run_cmd(cmd_num,sfd,cmd_buf))break;//cmd_numΪ��������
		run_cmd(cmd_num,sfd,cmd_buf);//cmd_numΪ��������
	}
    close(sfd);
    return 0;
}

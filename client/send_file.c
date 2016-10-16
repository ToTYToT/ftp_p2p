#include "head.h"

int send_file(int sfd,char *cmd_buf)
{
	printf("send_file %s\n",cmd_buf);
	int fd;
	int i=strlen(cmd_buf);
	*(cmd_buf+i)='\0';
    fd=open(cmd_buf+2,O_RDONLY,0777);
    if(-1==fd){
        perror("open");
        close(fd);
        return -1;
    }
	data d;
	memset(&d,0,sizeof(d));
	d.len=strlen(cmd_buf);
	strcpy(d.buf,cmd_buf);
	if(-1==send_n(sfd,(char*)&d,d.len+sizeof(int))){
        close(fd);
        return -1;
	}//发送命令
	if(-1==recv_n(sfd,(char*)&d,sizeof(int))){
        close(fd);
        return -1;
	};//接收回执，回执为空，则有错
	if(0==d.len){
		printf("the argument is wrong\n");
		return -1;
	}
	while(memset(&d,0,sizeof(data)),(d.len=read(fd,d.buf,sizeof(d.buf)))>0){
		if(-1==send_n(sfd,(char*)&d,d.len+sizeof(int))){
            close(fd);
            return -1;
        }
	}
	send_n(sfd,(char*)&d,sizeof(int));
	printf("puts success\n");
	return 0;
}

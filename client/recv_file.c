#include "head.h"

int recv_file(int sfd,char *cmd_buf)
{
	//printf("recv_file %s\n",cmd_buf);
	int fd;
	int i=strlen(cmd_buf);
	*(cmd_buf+i)='\0';
    fd=open(cmd_buf+2,O_RDWR|O_CREAT|O_EXCL,0777);
    if(-1==fd){
		fd=open(cmd_buf+2,O_RDWR);
		recv_broken_file(sfd,fd,cmd_buf);
        return -1;
    }
	char cmd_file[100]={0};
	strcpy(cmd_file,cmd_buf);
	data d;
	memset(&d,0,sizeof(d));
	the_ltoa(0L,cmd_buf+strlen(cmd_buf));
	//printf("recv_file %s\n",cmd_buf);
	strcpy(d.buf,cmd_buf);
	d.len=strlen(d.buf);
	send_n(sfd,(char*)&d,d.len+sizeof(int));//发送命令
	if(-1==recv_n(sfd,(char*)&d,sizeof(int))){
        close(fd);
        return -1;//接收回执，回执为空，则有错
	}
	if(0==d.len){
		printf("the argument is wrong\n");
		close(fd);
		d.len=unlink(cmd_file+2);
		if(-1==d.len){
			perror("unlink");
			printf("recv_file unlink fail\n");
		}
		return -1;
	}
    while(1){
		memset(d.buf,0,sizeof(d.buf));
		d.len=0;
		if(-1==recv_n(sfd,d.buf,d.len)){
            close(fd);
            return -1;
		}
        if(d.len>0){
			if(-1==recv_n(sfd,d.buf,d.len)){
                close(fd);
                return -1;
            }
			if(-1==write(fd,d.buf,d.len))return -1;
        }else{
            break;
        }
	}
	printf("gets success\n");
	close(fd);
	return 0;
}

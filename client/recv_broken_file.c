#include "head.h"

int recv_broken_file(int sfd,int fd,char* cmd_buf)
{
	//printf("recv_broken_file %s\n",cmd_buf);
	//struct stat *buf;
	struct stat buf;
	memset(&buf,0,sizeof(buf));
	fstat(fd,&buf);
	//printf("recv_file %ld,%s\n",buf.st_size,cmd_buf);
	the_ltoa(buf.st_size,cmd_buf+strlen(cmd_buf));
//	strncat(cmd_buf,(char*)&(buf.st_size),sizeof(long));
	//printf("recv_file %s\n",cmd_buf);
	lseek(fd,0,SEEK_END);
	data d;
	memset(&d,0,sizeof(d));
	d.len=strlen(cmd_buf);
	strcpy(d.buf,cmd_buf);
	send_n(sfd,(char*)&d,d.len+sizeof(int));//��������,����λΪ�ļ���ȡλ��
	recv_n(sfd,(char*)&d,sizeof(int));//���ջ�ִ����ִΪ�գ����д�
	if(0==d.len){
		printf("the argument is wrong\n");
		close(fd);
		return -1;
	}
	while(1){
		memset(d.buf,0,sizeof(d.buf));
		recv_n(sfd,(char*)&(d.len),sizeof(int));//�ļ�������ϣ��ȴ�����
        if(d.len>0){
			recv_n(sfd,d.buf,d.len);
			if(-1==write(fd,d.buf,d.len))return -1;
        }else{
            break;
        }
	}
	printf("gets success\n");
	close(fd);
	return 0;
}

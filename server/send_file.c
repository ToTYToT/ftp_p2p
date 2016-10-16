#include "head.h"

int send_file(int sfd,data *d)
{
	int fd;
	long file_len;
    the_file_position(d->buf,&file_len);
    //printf("send_file %ld,%s\n",file_len,d->buf);
    fd=open(d->buf,O_RDONLY);//打开失败发零,返回到命令界面
    if(-1==fd){
        send_str(sfd,"\0");
        close(fd);
        return -1;
    }
    d->len=1;
    if(-1==send_n(sfd,(char*)d,sizeof(int)))return -1;//not 0 is ready;
    lseek(fd,file_len,SEEK_SET);
    struct stat buf;
	memset(&buf,0,sizeof(buf));
	fstat(fd,&buf);
	//printf("send_file %ld\n",buf.st_size);
	if(buf.st_size-file_len>102400000){
        if(-1==send_file_use_mmap(sfd,fd,file_len,buf.st_size-file_len,buf.st_size)){
            close(fd);
            return -1;
        }
        send_str(sfd,"\0");
        if(-1==close(fd))perror("close");
        return 0;
	}
	while(memset(d,0,sizeof(data)),(d->len=read(fd,d->buf,sizeof(d->buf)))>0){
		if(-1==send_n(sfd,(char*)d,d->len+sizeof(int))){
            close(fd);
            return -1;
        }
	}
	send_str(sfd,"\0");
	close(fd);
	//send_n(sfd,(char*)d,sizeof(int));
	return 0;
}

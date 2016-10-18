#include "head.h"

int send_file(int sfd,data *d)
{
	int fd;
	unsigned long file_len;
    the_file_position(d->buf,&file_len);
    //printf("send_file %ld,%s\n",file_len,d->buf);
    fd=open(d->buf,O_RDONLY);//打开失败发零,返回到命令界面
    if(-1==fd){
    //    d->len=0;
	//	send_n(sfd,(char*)d,sizeof(int));
		send_str(sfd,"");
		close(fd);
        return -1;
    }
    d->len=1;
    if(-1==send_n(sfd,(char*)d,sizeof(int)))return -1;//not 0 is ready;
   // lseek(fd,file_len,SEEK_SET);
    struct stat buf;
	memset(&buf,0,sizeof(buf));
	fstat(fd,&buf);
	send_n(sfd,(char*)&(buf.st_size-file_len),sizeof(unsigned long));//发送文件待接受大小
	//printf("send_file %ld\n",buf.st_size);
	if(buf.st_size-file_len>102400000){
        if(-1==send_file_use_mmap(sfd,fd,file_len,buf.st_size-file_len,buf.st_size)){
            close(fd);
            return -1;
        }
   //     d->len=0;
	//	send_n(sfd,(char*)d,sizeof(int));
		send_str(sdf,"");
        if(-1==close(fd))perror("close");
        return 0;
	}
	send_data_package_file(sfd,fd,file_len,buf.st_size-file_len);
//	while(memset(d,0,sizeof(data)),(d->len=read(fd,d->buf,sizeof(d->buf)))>0){
//		if(-1==send_n(sfd,(char*)d,d->len+sizeof(int))){
//            close(fd);
//            return -1;
//        }
//	}
	send_str(sfd,"");
//	d->len=0;
//	send_n(sfd,(char*)d,sizeof(int));
	close(fd);
	//send_n(sfd,(char*)d,sizeof(int));
	return 0;
}

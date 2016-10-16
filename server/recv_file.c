#include "head.h"

int recv_file(int sfd,data *d)
{
	int fd;
    fd=open(d->buf,O_RDWR|O_CREAT|O_EXCL,0777);
    if(-1==fd){
        send_str(sfd,"\0");
        close(fd);
        return -1;
    }
    memset(d,0,sizeof(data));
    d->len=1;
	send_n(sfd,(char*)d,sizeof(int));//not 0 is ready
	while(1){
		//memset(d->buf,0,sizeof(d->buf));
		memset(d->buf,0,strlen(d->buf));
		d->len=0;
		if(-1==recv_n(sfd,d->len,sizeof(int))){
            close(fd);
            return -1;
		}
        if(d->len>0){
			if(-1==recv_n(sfd,d->buf,d->len)){
                close(fd);
                return -1;
            }
			if(-1==write(fd,d->buf,d->len))return -1;
        }else{
            break;
        }
	}
	close(fd);
	return 0;
}

#include "head.h"

int recv_file(int sfd,data *d)
{
	int fd;
    fd=open(d->buf,O_RDWR|O_CREAT|O_EXCL,0664);
    if(-1==fd){
		d->len=0;
        send_n(sfd,(char*)d,sizeof(int);
        close(fd);
        return -1;
    }
    memset(d,0,sizeof(data));
    d->len=1;
	send_n(sfd,(char*)d,sizeof(int));//not 0 is ready
	recv_n(sfd,(char*)d,sizeof(int));
	recv_n(sfd,d->buf,d->len);
	recv_data_package_file(sfd,fd,0,atol(d->buf));
	close(fd);
	return 0;
}

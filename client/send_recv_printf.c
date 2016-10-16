#include "head.h"

int send_recv_printf(int sfd,char * cmd_buf)
{
	//printf("send_recv_printf %s\n",cmd_buf);
	data d;
	memset(&d,0,sizeof(d));
	d.len=strlen(cmd_buf);
	strcpy(d.buf,cmd_buf);
	send_n(sfd,(char*)&d,d.len+sizeof(int));//·¢ËÍÃüÁî
	while(1){
		memset(&d,0,sizeof(data));
		recv_n(sfd,(char*)&(d.len),sizeof(int));
        if(d.len>0){
			recv_n(sfd,d.buf,d.len);
			printf("%s\n",d.buf);
        }else{
            break;
        }
	}
	return 0;
}

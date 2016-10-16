#include "head.h"

int send_str(int sfd,char * str)
{
    data d;
    memset(&d,0,sizeof(d));
    strcpy(d.buf,str);
    d.len=strlen(d.buf);
    if(-1==send_n(sfd,(char*)&d,d.len+sizeof(int)))return -1;
    return 0;
}

int recv_str(int sfd,char*str)
{
	int len=0;
	recv_n(sfd,(char*)&len,sizeof(int));
	if(len>0){
		if(-1==recv_n(sfd,str,len))return -1;
	}
	return 0;
}

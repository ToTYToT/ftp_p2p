#include "head.h"
#include<stdio.h>
int connect_server(int *sfd,char*s_addr,char*port)
{
	*sfd=socket(AF_INET,SOCK_STREAM,0);
    if(-1==*sfd){
        perror("socket");
        return -1;
    }
    struct sockaddr_in ser;
    memset(&ser,0,sizeof(ser));
    ser.sin_family=AF_INET;
    ser.sin_port=htons(atoi(port));
    ser.sin_addr.s_addr=inet_addr(s_addr);
    int ret;
    ret=connect(*sfd,(struct sockaddr*)&ser,sizeof(ser));
    if(-1==ret){
        perror("connect");
        close(*sfd);
        return -1;
    }
	return 0;
}
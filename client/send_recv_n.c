#include "send_recv_n.h"

int send_n(int sfd,char*p,int len)
{
	int total=0;
	int ret;
	while(total<len){
		if(-1==(ret=send(sfd,p+total,len-total,0)))return -1;
		total=total+ret;
	}
	return 0;
}

int recv_n(int sfd,char*p,int len)
{
	int total=0;
	int ret;
	while(total<len){
		if(0==(ret=recv(sfd,p+total,len-total,0)))return -1;
		total=total+ret;
	}
	return 0;
}

/*************************************************************************
	> File Name: send_recv_n.h
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Oct 2016 11:22:19 AM CST
 ************************************************************************/

#ifndef _SEND_RECV_N_H
#define _SEND_RECV_N_H

#include <sys/types.h>
#include <sys/socket.h>

int send_n(int sfd,char*p,int len);
int recv_n(int sdf,char*p,int len);
#endif

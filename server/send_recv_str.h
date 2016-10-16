/*************************************************************************
	> File Name: send_recv_str.h
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Oct 2016 11:55:39 AM CST
 ************************************************************************/

#ifndef _SEND_RECV_STR_H
#define _SEND_RECV_STR_H

#include <string.h>
#include "send_recv_n.h"

typedef struct {
    int len;
    char buf[1000];
}data;

int send_str(int sfd,char* str);
int recv_str(int sfd,char* str);
#endif

/*************************************************************************
    > File Name: send_recv_printf.h
    > Author:ToTYToT
    > Mail: 240008250@QQ.COM
    > Created Time: Sun 16 Oct 2016 06:22:29 PM CST
 ************************************************************************/
#ifndef _SEND_RECV_PRINTF_H
#define _SEND_RECV_PRINTF_H
#include "send_recv_n.h"
#include <stdio.h>
#include <string.h>
typedef struct {
	int len;
	char buf[1000]
}data;

int send_recv_printf(int sfd,char * cmd_buf);
#endif

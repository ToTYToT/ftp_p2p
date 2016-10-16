/*************************************************************************
    > File Name: run_cmd.h
    > Author:ToTYToT
    > Mail: 240008250@QQ.COM
    > Created Time: Sun 16 Oct 2016 06:16:43 PM CST
 ************************************************************************/
#ifndef _RUN_CMD_H
#define _RUN_CMD_H 
#include "send_recv_printf.h"
#include "send_file.h"
#include "recv_file.h"

int run_cmd(int cmd_num,int sfd,char* cmd_buf);
#endif

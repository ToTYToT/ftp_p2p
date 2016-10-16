/*************************************************************************
    > File Name: send_file.h
    > Author:ToTYToT
    > Mail: 240008250@QQ.COM
    > Created Time: Sun 16 Oct 2016 06:27:57 PM CST
 ************************************************************************/
#ifndef _SEND_FILE_H
#define _SEND_FILE_H

#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "send_recv_data_package.h"
#include "get_file_size.h"

int send_file(int sfd,char *cmd_buf);

#endif

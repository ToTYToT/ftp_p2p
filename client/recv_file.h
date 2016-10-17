/*************************************************************************
    > File Name: recv_file.h
    > Author:ToTYToT
    > Mail: 240008250@QQ.COM
    > Created Time: Sun 16 Oct 2016 08:34:18 PM CST
 ************************************************************************/
#ifndef _RECV_FILE_H
#define _RECV_FILE_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "send_recv_n"
#include "the_ltoa"
#include "recv_broken_file"
#include "send_recv_data_package"
typedef struct{
	int len;
	char buf[1000];
}data;
#endif

/*************************************************************************
	> File Name: send_recv_data_package.h
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Oct 2016 11:21:39 AM CST
 ************************************************************************/

#ifndef _SEND_RECV_DATA_PACKAGE_H
#define _SEND_RECV_DATA_PACKAGE_H

#include "send_recv_n.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
typedef struct {
    int len;
    char buf[1000];
}data;

int send_data_package(int sfd,int fd,int the_offset_position,int the_send_size);
int send_data_package_mmap(int sfd,int fd,char* mmap_addr,int the_offset_position,int the_send_size);
int recv_data_package_file(int sfd,int fd,int the_offset_position,int the_recv_size);
int recv_data_package_mmap(int sfd,int fd,char* mmap_addr,int the_offset_position,int the_recv_size);
#endif

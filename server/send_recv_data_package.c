/*************************************************************************
	> File Name: send_recv_data_package.c
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Oct 2016 10:35:50 AM CST
 ************************************************************************/

#include "send_recv_data_package.h"

int send_data_package(int sfd,int fd, int the_package_num)
{
    if(-1==lseek(fd,the_package_num*THE_PAGE_SIZE,SEEK_SET)){
        perror("lseek");
        return -1;
    }
    data d;
    int send_len=0;
    while(memset(d,0,sizeof(d)),send_len<64000&&(d.len=read(fd,d.buf,sizeof)>0)){
        send_n(sfd,(char*)d,d.len+sizeof(int)); 
        send_len+=d.len;
    }
    return 0;
}

int recv_data_package(int sfd,int fd, int the_package_num)
{
    if(-1==lseek(fd,the_package_num*THE_PAGE_SIZE,SEEK_SET)){
        perror("lseek");
        return -1;
    }
    data d;
    int send_len=0;
    while(memset(d,0,sizeof(d)),send_len<64000){
        recv(sfd,(char *)d.len,sizeof(int));
        if(d.len>0){
            recv_n(sfd,d.buf,d.len);
            send_len+=d.len;
        }else{
            break;
        }
    }
    return 0;  
}


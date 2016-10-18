/*************************************************************************
	> File Name: send_recv_data_package.c
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Oct 2016 10:35:50 AM CST
 ************************************************************************/

#include "send_recv_data_package.h"

int send_data_package(int sfd,int fd, int the_offset_position,int the_send_size)
{
    if(-1==lseek(fd,the_offset_position,SEEK_SET)){
        perror("lseek");
        return -1;
    }
    data d;
    int send_len=0;
    while(memset((char*)&d,0,sizeof(d)),send_len<the_send_size&&(d.len=read(fd,d.buf,sizeof(d.buf))>0)){
        send_n(sfd,(char*)&d,d.len+sizeof(int)); 
        send_len+=d.len;
    }
    return 0;
}

int send_data_package_mmap(int sfd,int fd,char*mmap_addr, int the_offset_position,int the_send_size)
{
    if(-1==lseek(fd,the_offset_position,SEEK_SET)){
        perror("lseek");
        return -1;
    }
    data d;
    int send_len=0;
    while(memset((char*)&d,0,sizeof(d)),the_send_size-send_len<sizeof(d.buf)){
        d.len=sizeof(d.buf);
        memcpy(d.buf,mmap_addr+the_offset_position+send_len,d.len);
        send_n(sfd,(char*)&d,d.len+sizeof(int)); 
        send_len+=d.len;
    }
    d.len=the_send_size-send_len;
    memcpy(d.buf,mmap_addr+the_offset_position+send_len,d.len);
    send_n(sfd,(char*)&d,d.len+sizeof(int)); 
    return 0;
}


int recv_data_package_file(int sfd,int fd, int the_offset_position,int the_recv_size)
{
    if(-1==lseek(fd,the_offset_position,SEEK_SET)){
        perror("lseek");
        return -1;
    }
    data d;
    int recv_len=0;
    while(memset((char*)&d,0,sizeof(d)),recv_len<the_recv_size){
        recv_n(sfd,(char *)d.len,sizeof(int));
        if(d.len>0){
            recv_n(sfd,d.buf,d.len);
            write(fd,d.buf,d.len);
            recv_len+=d.len;
        }else{
            break;
        }
    }
    return 0;  
}


int recv_data_package_mmap(int sfd,int fd,char* mmap_addr, int the_offset_position,int the_recv_size)//写入mmap
{
    data d;
    int recv_len=0;
    while(memset((char*)&d,0,sizeof(d)),recv_len<the_recv_size){
        recv_n(sfd,(char *)d.len,sizeof(int));
        if(d.len>0){
            recv_n(sfd,d.buf,d.len);
            memcpy(d.buf,mmap_addr+the_offset_position+recv_len,d.len);
            recv_len+=d.len;
        }else{
            break;
        }
    }
    return 0;  
}

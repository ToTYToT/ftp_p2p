#include "head.h"

int send_file_use_mmap(int sfd,int fd,long file_len,long the_send_len,long the_file_total_len)
{
    //printf("send_file_use_mmap %d %d %ld %ld %ld the arguments\n",sfd,fd,file_len,the_send_len,the_file_total_len);
    data d;
    char *mmap_addr=(char*)mmap(NULL,the_file_total_len ,PROT_READ,MAP_SHARED,fd,0);
    int i;
    for(i=1;the_send_len>=i*(sizeof(d.buf));i++){
        d.len=sizeof(d.buf);
        memcpy(d.buf,mmap_addr+file_len+(i-1)*sizeof(d.buf),d.len);
        if(-1==send_n(sfd,(char*)&d,d.len+sizeof(int))){
            //printf("send_file_use_mmap mmap_send_n_1 %d %d %ld %ld %ld the arguments\n",sfd,fd,file_len,the_send_len,the_file_total_len);
            return -1;
        }
    }
    d.len=the_send_len-(i-1)*sizeof(d.buf);
    memcpy(d.buf,mmap_addr+file_len+(i-1)*sizeof(d.buf),d.len);
    if(-1==send_n(sfd,(char*)&d,d.len+sizeof(int))){
       // printf("send_file_use_mmap mmap_send_n_2 %d %d %ld %ld %ld the arguments\n",sfd,fd,file_len,the_send_len,the_file_total_len);
        return -1;
    }
	return 0;
}


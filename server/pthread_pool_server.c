#include "head.h"

int main(int argc,char *argv[])
{
    if(argc!=4){
        printf("port,queue_qum,pth_num\n");
        return -1;
    }
    signal_catch();
    int q_num=atoi(argv[2]);
    int p_num=atoi(argv[3]);
    ppth_info pth;
    pth=(ppth_info)calloc(1,sizeof(pth_info));
    pthread_pool_init(pth,p_num,q_num);
    pthread_pool_create(pth);
    int sfd=socket(AF_INET,SOCK_STREAM,0);
    if(-1==sfd){
        perror("socket");
        return -1;
    }
    struct sockaddr_in ser;
    memset(&ser,0,sizeof(ser));
    ser.sin_family=AF_INET;
    ser.sin_addr.s_addr=INADDR_ANY;
    ser.sin_port=htons(atoi(argv[1]));
    int ret=bind(sfd,(struct sockaddr*)&ser,sizeof(ser));
    if(-1==ret){
        perror("bind");
        return -1;
    }
    listen(sfd,q_num);
    int new_fd;
    pqnode new_q;
    struct sockaddr_in client_addr_info;
    int client_addr_len=sizeof(client_addr_info);
    while(1){
        new_fd=accept(sfd,(struct sockaddr*)&client_addr_info,&client_addr_len);
        if(-1==new_fd){
            perror("accept");
            return -1;
        }
        new_q=(pqnode)calloc(1,sizeof(qnode));
        new_q->fd=new_fd;
        memcpy((char*)&new_q->client_info,(char*)&client_addr_info,client_addr_len);
        queue_add(&pth->que,new_q);
        pthread_cond_signal(&pth->cond);
    }
    return 0;
}

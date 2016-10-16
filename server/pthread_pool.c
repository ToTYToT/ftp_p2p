#include "head.h"

void*pth_get_cmd(void*p1)
{
    ppth_info p=(ppth_info)p1;
    pqnode pq;
    while(1){
        pthread_mutex_lock(&p->que.mutex);
        while(NULL==p->que.phead->next){
            pthread_cond_wait(&p->cond,&p->que.mutex);
        }
        queue_del(&p->que,&pq);
        pthread_mutex_unlock(&p->que.mutex);
        signal_catch();
        char buf[1000]={0};
        sprintf(buf,"%s%s%s",inet_ntoa(pq->client_info.sin_addr),",","login");
        syslog_write(buf);
        //syslog_write(inet_ntoa(pq->client_info.sin_addr));
        char pwd[MY_NAME_LEN]="/home/t520/linux/1";
       // char *pwd;
       // pwd=(char*)calloc(1,MY_NAME_LEN);
        //memcpy(pwd,"/home/t520/linux/1",18);
        int user_login_times=0;
        int user_login_result=0;
        for(user_login_times=0;user_login_times<5;user_login_times++){
                //char *tmp_pwd;
                //tmp_pwd=(char*)calloc(1,MY_NAME_LEN);
                user_login_result=user_login(inet_ntoa(pq->client_info.sin_addr),pq->fd,pwd+strlen(pwd));
                if(0==user_login_result){
                    break;
                }
        }
        if(5==user_login_times){
            close(pq->fd);
            continue;
        }

		int len;
		//printf("ready\n");
		while(1){
		    len=0;
		    memset(buf,0,sizeof(buf));
		    //printf("ready\n");
            recv_n(pq->fd,(char*)&len,sizeof(int));
            recv_n(pq->fd,buf,len);
            int ret=gets_cmd(buf);//·µ»Øº¯Êý´úÂë
            if(8==ret){
                //printf("byebye\n");
                break;
            }
            //printf("gets_cmd %s num=%d\n",buf,ret);
            syslog_write(buf);
            run_cmd(ret,pq->fd,buf,pwd);
            // if(-1==run_cmd(ret,pq->fd,buf,pwd))break;
		}
		memset(buf,0,sizeof(buf));
		sprintf(buf,"%s%s%s",inet_ntoa(pq->client_info.sin_addr),",","logout");
        syslog_write(buf);
		//syslog_write(buf);
		//syslog_write(inet_ntoa(pq->client_info.sin_addr));
		close(pq->fd);
		//free(pwd);
    }
    return NULL;
}

int pthread_pool_init(ppth_info p,int pn,int qn)
{
    p->pth=(pthread_t*)calloc(pn,sizeof(pthread_t));
    p->p_num=pn;
    pthread_cond_init(&p->cond,NULL);
    p->que.phead=(pqnode)calloc(1,sizeof(q_info));
    p->que.ptail=p->que.phead;
    p->q_num=qn;
    p->get_cmd=pth_get_cmd;
    return 0;
}
int pthread_pool_create(ppth_info p)
{
    if('1'==p->flag){
        return -1;
    }
    int i;
    for(i=0;i<p->p_num;i++)
    {
        pthread_create(p->pth+i,NULL,p->get_cmd,(void*)p);
    }
    p->flag='1';
}

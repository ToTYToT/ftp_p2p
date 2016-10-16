#include "head.h"

int queue_del(pq_info p,pqnode* q1)
{
    pqnode q;
    q=p->phead->next;
    p->phead->next=q->next;
    if(NULL==p->phead->next){
        p->ptail=p->phead;
    }
    *q1=q;
    return 0;
}

int queue_add(pq_info p,pqnode q)
{
    pthread_mutex_lock(&p->mutex);
    p->ptail->next=q;
    p->ptail=q;
    pthread_mutex_unlock(&p->mutex);
}

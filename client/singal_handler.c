#include "head.h"

void handler(int num)
{
    //printf("%d\n",num);
}

int signal_catch()
{
    int i;
    for(i=0;i<32;i++){
        signal(i,handler);
    }
}

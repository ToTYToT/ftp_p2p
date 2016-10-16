#include "head.h"

int the_file_position(char*buf,long *file_len)
{
    int i,j;
    for(i=0,j=10;*(buf+j)!='\0';j++,i++);
    *file_len=atoi(buf+i);
    strcpy(buf+i,"\0");
    //printf("the_file_position %ld,%s\n",*file_len,buf);
}

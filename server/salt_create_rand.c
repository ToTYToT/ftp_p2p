#include "head.h"
int salt_create_rand(char *my_salt,int my_salt_len)//my_salt_len有效位为16位，所以my_salt_len<=16;
{
    char *str="0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZabcedefghijklmnopqrstuvwxyz,/.\"'<>?";
    int i,lstr;
    char ss[2]={0};
   // printf("%s\n%d\n",str,strlen(str));
    lstr=strlen(str);
    srand((unsigned)time((time_t*)NULL));
    for(i=1;i<=my_salt_len;i++){
        sprintf(ss,"%c",str[(rand()%lstr)]);
        strcat(my_salt,ss);
    }
    return 0;
}

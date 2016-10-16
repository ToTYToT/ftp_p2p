#include "head.h"

int strcat_the_mysql_cmd(char *query_str,char*cmd,...)//参数必须以0结尾，或者以NULL；且cmd参数不能为NULL
{
    int i=0;
    while(*(&cmd+i)!=NULL){
        strcat(query_str,"\'");
        strcat(query_str,*(&cmd+i));
        strcat(query_str,"\'");
        strcat(query_str,",");
        i++;
    }
    *(query_str+strlen(query_str)-1)=')';
}

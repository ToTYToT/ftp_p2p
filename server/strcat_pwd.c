#include "head.h"

int strcat_pwd(char *cmd,char*pwd)//将cmd变为文件路径
{
    char dirname[100]={0};
    strcpy(dirname,pwd);
    strcat(dirname,"/");
    strcat(dirname,cmd+2);
    strcpy(cmd,dirname);
    //printf("strcat_pwd %s\n",cmd);
}

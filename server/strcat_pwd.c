#include "head.h"

int strcat_pwd(char *cmd,char*pwd)//��cmd��Ϊ�ļ�·��
{
    char dirname[100]={0};
    strcpy(dirname,pwd);
    strcat(dirname,"/");
    strcat(dirname,cmd+2);
    strcpy(cmd,dirname);
    //printf("strcat_pwd %s\n",cmd);
}

#include "head.h"

int login_write(char*cmd)
{
    time_t timep;
    struct tm *p;
    char data_info[20]={0};
    time(&timep);
    p=gmtime(&timep); /* 获取当前时间 */
    sprintf(data_info,"%4d/%2d/%2d/%2d:%2d:%2d",(1900+p->tm_year),(1+p->tm_mon),p->tm_mday,(p->tm_hour+8),p->tm_min,p->tm_sec);
    insert_mysql_syslog(data_info,cmd);
}

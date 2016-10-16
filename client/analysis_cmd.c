#include "head.h"

int analysis_cmd(char *cmd_buf)
{
	int i;
	int len;
	char buf[CMD_LEN]={0};
	char cmd_str[CMD_NUM][10]={"\0","cd ","ls","pwd","mkdir ","remove ","gets ","puts ","quit"};
	for(i=1;i<CMD_NUM;i++){
		len=strlen(cmd_str[i]);
		if(!strncmp(cmd_str[i],cmd_buf,strlen(cmd_str[i]))){
			strcpy(buf,cmd_buf+strlen(cmd_str[i]));
			memset(cmd_buf,0,strlen(cmd_buf));
			strncpy(cmd_buf,cmd_str[i],2);//取每天指令的前两个字母
			strcat(cmd_buf,buf);//取指令参数,cmd_buf格式为XX+filename
			//printf("analysis_cmd %s, cmd_num=%d\n",cmd_buf,i);
			return i;
		}
	}
	return 0;
}

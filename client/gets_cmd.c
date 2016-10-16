#include "head.h"

int gets_cmd(char *cmd_buf)
{
	int ret;
	int len;
    while(1){
        printf("the cmd is \"cmd argument\" (quit for quit) \n");
        memset(cmd_buf,0,CMD_LEN);
        if((ret=read(0,cmd_buf,CMD_LEN))<2){
            fflush(0);
		    system("clear");
        }else{
			len=strlen(cmd_buf);
			*(cmd_buf+len-1)='\0';
			//printf("gets_cmd %s %c len=%d\n",cmd_buf,*(cmd_buf+len-1),len);
            break;
        }
    }
   system("clear");
   return 0;
}

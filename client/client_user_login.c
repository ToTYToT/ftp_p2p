#include "client_user_login.h"

int client_user_login(int sfd,char**user_name)
{
	char buf[108]={0};
	recv_str(sfd,buf);
	printf("%s\n",buf);
	memset(buf,0,sizeof(buf));
	int ret=read(0,buf,sizeof(buf));
	*(buf+strlen(buf)-1)='\0';
	fflush(0);
	//printf("ret=%d,buf=%s\n",ret,buf);
	send_str(sfd,buf);//send user_name
    *user_name=(char*)calloc(1,strlen(buf));
    strcpy(*user_name,buf);
	memset(buf,0,sizeof(buf));
	recv_str(sfd,buf);
	printf("%s\n",buf);
	memset(buf,0,sizeof(buf));
	ret=read(0,buf,sizeof(buf));
	*(buf+strlen(buf)-1)='\0';
	fflush(0);
	//printf("ret=%d,buf=%s\n",ret,buf);
	char user_salt[100]={0};
	recv_str(sfd,user_salt);
	//printf("%s\n",user_salt);
	salt_password(user_salt,buf);
	//printf("salt_password buf:%s520\n",buf);
	send_str(sfd,buf);
	memset(buf,0,sizeof(buf));
	recv_str(sfd,buf);
	if(!strcmp("success",buf)){
		return 0;
	}else{
		return -1;
	}
}

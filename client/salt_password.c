#include "salt_password.h"

int	salt_password(char*user_salt,char*buf)
{
	//printf("salt_password salt buf:%s %s\n",buf,user_salt);
	char *encrypted = NULL;
	char tmp_user_salt[22]={0};
	sprintf(tmp_user_salt,"%s%s\n","$6$",user_salt);
	if((encrypted = crypt(buf,tmp_user_salt)) == NULL)
    {
        fprintf(stderr, "crypt error:%s\n", strerror(errno));
    }
	//printf("salt_password encrypted:%s520\n",encrypted);
	memset(buf,0,strlen(buf));
	//printf("salt_password buf:%s520\n",buf);
	int i;
	for(i=0;*(encrypted+i+3)!='$';i++);
	memcpy(buf,encrypted+4+i,strlen(encrypted+4+i));
	//printf("salt_password buf:%s_520\n",buf);
	return 0;
}

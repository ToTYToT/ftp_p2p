#include "head.h"

char* the_ltoa(long num,char*str)//规范为10位，前位不足补零。
{
	char index[]="0123456789";	
	int i=0,j;
	do{
		str[i++]=index[num%10];
		num/=10;
	}while(num);
	while(i<10)
	{
		str[i++]='0';
	}
	str[i]='\0';
	char temp;
	for(j=0;j<=4;j++)
	{
		temp=str[j];
		str[j]=str[9-j];
		str[9-j]=temp;
	}
	return str;
}
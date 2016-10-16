#include "head.h"

int gets_cmd(char*p)
{
	char cmd_str[N][10]={"cd ","ls\n","pwd","gets","puts","mkdir","remove","quit"};
	int i;
	for(i=0;i<N;i++){
        if(!strncmp(p,cmd_str[i],2)){
            return i;
        }
	}
}

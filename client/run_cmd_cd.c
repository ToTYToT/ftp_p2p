#include "head.h"

int run_cmd_cd(int sfd,char *cmd,char*pwd)
{
   // printf("run_cmd_cd cmd=%s \n",cmd);//ӦΪXX+argument
    char cmd_buf[LEVEL_LEN][MY_NAME_LEN]={0};
    int i,j;
    int lever[LEVEL_LEN]={0};
    char tmp_pwd[MY_NAME_LEN]={0};
    int n=0;
    //printf("strchr =%d\n",strchr(cmd,'/')-cmd);
    for(j=0,i=0;'\0'!=*(cmd+i);i++){
        if('/'==*(cmd+i)){
            lever[j]=i;
            j++;
        }
    }
    lever[j]=i;
    for(i=0;lever[i+1]>0;i++){
        strncpy(cmd_buf[i+1],cmd+lever[i],lever[i+1]-lever[i]);
       // printf("%s\n",cmd_buf[i+1]);
    }
    strcat(cmd_buf[0],"/");
    if(0!=lever[0]){
        strncpy(cmd_buf[0]+1,cmd+2,lever[0]-2);
        //printf("%s\n",cmd_buf[0]);
    }else{
        for(j=1;'/'!=*(pwd+THE_SERVER_PATH_LEN+j);j++);
        memset(pwd+j,0,strlen(pwd+j));
    }
    int cur_lever=0;
    for(i=0;'\0'!=*(pwd+19+i);i++){
        if('/'==*(pwd+19+i)){
            cur_lever++;
        }
    }
    //printf("cur_lever=%d\n",cur_lever);
    char cur_pwd[MY_NAME_LEN]={0};
    strcpy(cur_pwd,pwd);
    //("pwd=%s cur_pwd=%s\n",pwd,cur_pwd);
    DIR * is_dir;
    n=0;
   // printf("cmd_buf=%s,1=%d\n",cmd_buf[1],1);
    for(i=0;cmd_buf[i][0]!='\0';i++){
        //printf("cmd_buf=%s,i=%d\n",cmd_buf[i],i);
        if(!strcmp(cmd_buf[i],"/..")){
            if(cur_lever!=0){
                cur_lever--;
              //  printf("cur_lever=%d\n",cur_lever);

                for(j=0,n=0;'\0'!=*(pwd+19+j);j++){
                    if('/'==*(pwd+19+j)){
                        n=j;
                    }
                }
                memset(pwd+19+n,0,strlen(pwd+19+n));
                strcpy(cur_pwd,pwd);
               // printf("pwd=%s,i=%d %d %d\n",pwd,i,strrchr(pwd,'/')-pwd,19+n);
              //  printf("cmd_buf=%s,i=%d\n",cmd_buf[i+1],i+1);
             //   printf("cur_lever=%d\n",cur_lever);
                continue;
            }else{
               // send_str(sfd,"\0");
              // printf("break here1\n");
                break;
            }
        }
        if(!strcmp(cmd_buf[i],"/.")||!strcmp(cmd_buf[i],"/")){
            continue;
        }
        strcat(cur_pwd,cmd_buf[i]);
        if((is_dir=opendir(cur_pwd))!=NULL){
            closedir(is_dir);
            strcpy(pwd,cur_pwd);
            cur_lever++;
        }else{
           // send_str(sfd,"\0");
         //  printf("break here2\n");
            break;
        }
    }
   // printf("pwd=%s cur_pwd=%s\n",pwd,cur_pwd);
  //  printf("cur_lever=%d\n",cur_lever);
    send_str(sfd,pwd+18);
    send_str(sfd,"\0");
}

#include "head.h"

int run_cmd_ls(int sfd,char *cmd,char*pwd)
{
    DIR* show_dir;
    show_dir=opendir(pwd);
    if(NULL==show_dir){
        send_str(sfd,"\0");
        return -1;
    }//ÁôÓÃ
    struct dirent *p_dir;
    while((p_dir=readdir(show_dir))!=NULL){
        if(!strncmp(".",p_dir->d_name,1)){
            continue;
        }
        send_str(sfd,p_dir->d_name);
    }
    send_str(sfd,"\0");
    return 0;
}

#include "get_file_size.h" 

unsigned long get_file_size(int fd)  
{  
    unsigned long filesize = -1;      
    struct stat statbuff;  
    if(fstat(path, &statbuff) < 0){  
        return filesize;  
    }else{  
        filesize = statbuff.st_size;  
    }  
    return filesize;  
}  

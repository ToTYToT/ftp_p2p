/*************************************************************************
    > File Name: _DS.h
    > Author:ToTYToT
    > Mail: 240008250@QQ.COM
    > Created Time: Mon 17 Oct 2016 08:49:10 PM CST
 ************************************************************************/

 /// @file    _DS.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-17 20:49:10
 ///

typedef struct user_dir{
    int user_id;
    char name[20];
    int per_dir_id;
    int lever;
    int md5sum_id;
}user_dir,*user_dir_p;

typedef struct md5sum_all{
    int md5sum_id;
    char md5sum_str[33];
    struct md5sum_all *next;
}md5sum_all,*md5sum_all_p;

typedef struct {
    int len;
    char buf[1000];
}data;



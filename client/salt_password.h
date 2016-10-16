/*************************************************************************
	> File Name: salt_password.h
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Oct 2016 04:40:21 PM CST
 ************************************************************************/

#ifndef _SALT_PASSWORD_H
#define _SALT_PASSWORD_H
#define _XOPEN_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int salt_password(char*user_salt,char*buf);
#endif

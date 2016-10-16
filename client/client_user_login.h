/*************************************************************************
	> File Name: client_user_login.h
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Oct 2016 04:35:41 PM CST
 ************************************************************************/

#ifndef _CLIENT_USER_LOGIN_H
#define _CLIENT_USER_LOGIN_H

#include "send_recv_str.h"
#include "salt_password.h"

int client_user_login(int sfd,char**user_name);
#endif

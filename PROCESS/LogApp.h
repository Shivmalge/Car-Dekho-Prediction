#pragma once
#include <iostream>
#include <string.h>
#include "Admin.h"
#include "User.h"

using namespace std;

class LogApp
{
public:
	LogApp();
	bool check_username(string& username);
	void register_user();
	bool login_user();
	bool LogApp::admin_login();
	
	void Login(Admin* admin,User* user);
};

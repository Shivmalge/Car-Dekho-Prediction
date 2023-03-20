#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class LogApp
{




public:
	LogApp();
	bool check_username(string username);
	void register_user();
	bool login_user();
	bool admin_login();
	void Login();
};


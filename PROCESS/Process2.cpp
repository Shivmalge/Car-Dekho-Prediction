#include "stdafx.h"
#include <iostream>
#include <string.h>
#include "User.h"
#include "process.h"
#include "Admin.h"
#include "LogApp.h"

int main()
{
	LogApp app;
	Admin* admin = Admin::getInstan();
	User user;
	app.Login(admin,&user);
};
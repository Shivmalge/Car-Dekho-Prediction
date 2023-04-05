#include "stdafx.h"
#include <conio.h>
#include "LogApp.h"
#include "User.h"
#include "Admin.h"
#include "Process.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <string>

using namespace std;

LogApp::LogApp()
{

}

//Function to check if username is already exist in the file

bool LogApp::check_username(string& username)
{
	ifstream file("C:\\Users\\sme55\\Documents\\Visual Studio 2015\\Projects\\Process\\Users.txt");
	string line;
	while (getline(file, line))
	{
		if (line.substr(0,username.length()) == username)
		{
			file.close();
			return true;
		}
		file.close();
		return false;
	}
	return false;
}

//Function to register a new user 
void LogApp::register_user()
{
	string username, password;
	cout << "\tEnter username: " << endl;
	cin >> username;
	_getch();
	if (check_username(username))
	{
		cout << "----The USERNAME is already exists. Please choose different one------" << endl;
		return;
	}
	cout << "\tEnter a Password: " << endl;
	cin >> password;
	cout << endl;
	ofstream file("C:\\Users\\sme55\\Documents\\Visual Studio 2015\\Projects\\Process\\Users.txt",ios::app);
	file << username << " " << password << endl;
	file.close();
	cout << "**************** User registered successflly****************" << endl<<endl;
}

//Function to Login existing user
bool LogApp::login_user()
{
	string username, password;
	cout << "\tEnter your username: " << endl;
	cin >> username;
	cout << "\tEnter password: " << endl;
	cin >> password;
	ifstream file("C:\\Users\\sme55\\Documents\\Visual Studio 2015\\Projects\\Process\\Users.txt");
	string line;
	while(getline(file,line))
	{ 
		if (line.substr(0, username.length()) == username)
		{
			string stored_pass = line.substr(username.length()+1, password.length());
			/*for (int i = 0; i < stored_pass.length(); i++) {
				cout << stored_pass[i];
			}*/
			//cout << stored_pass;

			if (stored_pass == password)
			{
				file.close();
				cout << "*******Logged in successfully*******" << endl<<endl;
				return true;
			}
			else
			{
				file.close();
				cout << "********Incorrect password: Please try again********" << endl<<endl;
				return false;
			}
		}
	}
	return false;
}


//Admin Login Function 
bool LogApp::admin_login()
{
	string adminname, password;
	cout << "\tEnter admin name: " << endl;
	cin >> adminname;
	cout << "\tEnter password: " << endl;
	cin >> password;
	cout << endl;
	if (adminname == "Admin" && password == "Admin123")
	{
		cout << "*******Admin Logged in successfully********"<<endl<<endl;
		return true;
	}
	else
	{
		cout << "****Invalid admin name and password****" << endl<<endl;
		return false;
	}
	
}


//Main Function 
void LogApp::Login(Admin* admin, User* user)
{
	int choice;
	while (true)
	{
		cout << "********Hello Welcome to page!*********" << endl << endl;
		cout << "1. Register User " << endl;
		cout << "2. User Login " << endl;
		cout << "3. Admin Login " << endl;
		cout << "4. Exit " << endl;
		cout << "Enter your choice: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			register_user();
			break;
		
		case 2:
			if (login_user())
			{
				user->ProcessUserMenu(admin);

			}
			break;

		case 3:
			if (admin_login())
			{
				admin->ProcessAdminMenu();

			}
			break;

		case 4:
			break;
		
		default:
			cout << "*********** Invalid choice. Please try again. **********" << endl<<endl;
		}
	}
}

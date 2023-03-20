#include "User.h"
#include "Process.h"
#include <iostream>
#include <string.h>
using namespace std;

//Funtion to display user menu
void User::processUserMenu(void)
{
	cout << "\n--------------------------- User MENU ---------------------------------\n";
	cout << "Select what you want to perform: \n";
	cout << "1. View All Processes\n2. Run process\n0. Quit \n";

	int choice;

	cout << "\t\tEnter Choice: ";
	cin >> choice;
	if (choice < 0 || choice > 2)
	{
		cout << "\nError: Invalid Option Chosen: " << choice << ". Try Again..\n";
	}
	else if (choice == 2)
	{
		Process run;
		run.run_process();
	}
	else
	{
		cout << "\nFunctionalities yet to be updated" << endl << endl;
	}
}
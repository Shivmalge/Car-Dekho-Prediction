#include "Admin.h"
#include "Process.h"
#include <iostream>
#include <string.h>
using namespace std;

//Function to display Admin menu
void Admin::processAdminMenu(void)
{
	cout << "\n--------------------------- Admin MENU ---------------------------------\n";
	cout << "Select what you want to perform: \n";
	cout << "1. View All Processes\n2. Run Process\n3. Add process \n0. Quit \n";

	int choice;
	cout << "\t\tEnter Choice: ";
	cin >> choice;
	if (choice < 0 || choice > 6)
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
#include "stdafx.h"
#include "User.h"
#include "Process.h"
#include "Admin.h"
#include <iostream>
#include <string.h>


using namespace std;



void User::setQuatumTime(int Quantum)
{
	quantum = Quantum;
}

int User::getQuantumTime()
{
	return quantum;
}



//Function to Display User Menu
void User::ProcessUserMenu(Admin* admin)
{
	cout<<"\n--------------------------- User MENU ---------------------------------\n";
	cout << "Select what you want to perform: \n";
	cout << "01. view all process\n 02. Select process\n 0. Quit\n ";

	int choice;
	cout << "\nEnter your choice: ";
	cin >> choice;
	if (choice < 0 || choice >2)
	{
		cout << "\nError: Invalid option chosen " << choice << " Try Again..\n"<<endl;
	}

	else if (choice == 1)
	{
		admin->view_processes();
	}

	
	else if (choice == 2)
	{	
		int count;
		cout << "Enter no of processes" << endl;
		cin >> count;
		admin->selectProcess(count);
	}

	else
	{
		cout << "\nFunctionalities yet to be updated..";
	}
}

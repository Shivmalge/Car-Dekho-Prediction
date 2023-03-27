#include "Admin.h"
#include "Process.h"
#include <iostream>
#include <string.h>
using namespace std;


Admin::Admin() {
	
}



void Admin::createProcess() 
{
	Process* newProcess = new Process();
	string name;
	int burst;
	cout << "Enter the name of the process: ";
	cin >> name;
	newProcess.setname(name);

	cout << "Enter the time cycles required to complete the process: ";
	cin >> burst;
	newProcess.setBurstTime(burst);

	//cout << "Enter the time cycles for the process to go to wait state: ";
	//cin >> newProcess.timeToWait;
	processList.push_back(newProcess);
	cout << "Process added successfully." << endl;
}


void Admin::displayProcess() 
{
	cout << "Process List:" << endl;
	for (auto& process : processList) {
		cout << "Name: " << process.name<< " Burst Time  " << process.burst << endl;
	}
}


void Admin::updateProcess(int id)
{

	for (auto& process : processList)
		{
			if (process.getiD() == id)
			{
				cout << "Enter the name of the process: ";
				cin >> process.name;//if not worked the use getter setter
				cout << "Enter the burst time for the process: ";
				cin >> process.burst;
				//cout << "Enter the time cycles for the process to go to wait state: ";
				//cin >> process.time;
				cout << "Process updated successfully." << endl;
			}
		}	cout << "update failed please check the process ID." << endl;
}

void Admin::deleteProcess(int id, int index)
{
	for (auto& process : processList)
		{
			if (process.getiD() == id)
			{
				processList.erase(processList.begin() + index);
				cout << "Process deleted successfully." << endl;
			}
		}
}

void Admin::view_processes()
{	
	for (int i = 0; i < processList.size(); i++)
	{
		cout << "The process ID is " << processList[i].getiD() << ", process name is " << processList[i].getname() << " and the process burst time is " << processList[i].getBurstTime() << endl;
	}
}

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

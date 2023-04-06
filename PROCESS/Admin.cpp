
#pragma once
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <ctime>

#include "Admin.h"
#include "Process.h"

using namespace std;


Admin* Admin::admin = NULL;

Admin::Admin() {
	
}


void Admin::createProcess() 
{
	Process newProcess;
	string name;
	int burst;
	int ID;
	
	cout << "Enter the ID of the process: " << endl;
	cin >> ID;
	newProcess.setiD(ID);

	cout << "Enter the name of the process: "<<endl;
	cin >> name;
	newProcess.setname(name);

	cout << "Enter the Burst time for the process: ";
	cin >> burst;
	newProcess.setBurstTime(burst);

	//cout << "Enter the time cycles for the process to go to wait state: ";
	//cin >> newProcess.timeToWait;

	processList.push_back(newProcess);
	cout << "Process added successfully." << endl << endl;
}


void Admin::displayProcess() 
{
	cout << "Process List:" << endl;
	for (auto& process : processList) {
		cout << "Name: " << process.name<< " Burst Time  " << process.burst << endl;
	}
}


void Admin::updateProcess()
{
	int id;
	cout << "Enter the id of the process you want to update: " << endl;
	cin >> id;
	for (auto& process : processList)
		{	

		if (process.getID() == id)
		{	
			string Name;
			cout << "Enter the updated name of the same process: ";
			cin >> Name;
			process.setname(Name);

			int Burst;
			cout << "Enter the updated burst time of the same process: ";
			cin >> Burst;
			process.setBurstTime(Burst);   

			//cout << "Enter the time cycles for the process to go to wait state: ";
			//cin >> process.time;
			cout << "Process updated successfully." << endl << endl;
		}
		
	}
		
}

void Admin::deleteProcess(int index) {

	if (index >= 0 && index < processList.size()) {
		processList.erase(processList.begin() + index);
		cout << "Process deleted successfully" << endl;
	}
	cout << "Please select the correct index" << endl;
}


/*void Admin::deleteProcess()
{	
	int id;
	cout << "Enter the id of the process: " << endl;
	cin >> id;
	int size_of_processlist = sizeof(processList);
	cout << size_of_processlist;

	for (auto& process : processList)
		{
		if (id <= size_of_processlist & id != 0)
		{
			processList.erase(processList.begin() + id-1);
			cout << "Process deleted successfully." << endl;
		}
		
			/*if (process.getID() == id)
			{
				processList.erase(processList.begin()+index);
				cout << "Process deleted successfully." << endl;
			}
		}	
	cout << "****Process ID not found. Please check and enter correct process ID***" << endl<<endl;
}*/




void Admin::view_processes()
{		
	cout << "The size of the processList is " << processList.size() << endl;
	for (int i = 0; i < processList.size(); i++)
	{
		cout << "The process ID is " << processList[i].getID() << ", process name is " << processList[i].getname() << " and the process burst time is " << processList[i].getBurstTime() << endl << endl;
	}
}


void Admin::run_process(vector <Process> selectedList)
{
	int quantum;
	cout << "Enter the Time Quantum for the processes: " << endl;
	cin >> quantum;


	/*while (true)
	{
		bool all_completed = true;
		for (int i = 0; i < selectedList.size(); i++)
		{
			if (selectedList[i].state != ProcessState::COMPLETED)
			{
				all_completed = false;
				break;
			}
		}
		if (all_completed)
			break;
	*/
		
		for (int i = 0; i < selectedList.size(); i++)
			{
				while(selectedList[i].state != 3)
				{
					selectedList[i].currTime = selectedList[i].getBurstTime();
					if (selectedList[i].currTime < quantum)
					{	
						selectedList[i].timeInRunning += selectedList[i].currTime;
						selectedList[i].time_for_completion += selectedList[i].timeInRunning + selectedList[i].timeInWaiting + selectedList[i].timeInStopped;
						selectedList[i].currTime = 0;
						selectedList[i].state = 3;
						cout << "Process is Completed and the process completion time is " << selectedList[i].time_for_completion << endl;
			
					}

					else if (selectedList[i].currTime >= quantum)
					{	
						selectedList[i].timeInRunning += selectedList[i].currTime;
						selectedList[i].time_for_completion += selectedList[i].timeInRunning + selectedList[i].timeInWaiting + selectedList[i].timeInStopped;
						selectedList[i].currTime -= quantum;
						if (selectedList[i].currTime == 0)
						{
							selectedList[i].state = 3;
							cout << "Process is Completed and the process completion time is " << selectedList[i].time_for_completion << endl;
							break;
						}
						else
						{
							selectedList[i].state = get_random_status();
							if (selectedList[i].state == 1)
							{
								selectedList[i].timeInWaiting += 3;
								selectedList[i].time_for_completion += selectedList[i].timeInWaiting;

								selectedList[i].state = 0;
							}
							else if (selectedList[i].state == 2)
							{
								selectedList[i].timeInStopped += 1;
								selectedList[i].time_for_completion += selectedList[i].timeInStopped;

								if (selectedList[i].currTime == 0)
								{
									selectedList[i].state = 3;
									cout << "Process is Completed and the process completion time is " << selectedList[i].time_for_completion << endl;
									break;
								}
								else
								{
									selectedList[i].state = 0;
								}
							}
						}
					
					}
				}
			cout << "The Waiting time for the first process is " << selectedList[i].timeInWaiting << endl;
			cout << "The Stopped time for the first process is " << selectedList[i].timeInStopped << endl;
			cout << "The Running time for the first process is " << selectedList[i].timeInRunning << endl;
			} 

		
		


	/*for (int i = 0; i < processList.size(); i++) {
		if (processList[i].state == ProcessState::READY && processList[i].cpuId == -1) {
			processList[i].cpuId = i + 1;
		}
	}*/
	
}


//void Admin::operation()

int Admin::get_random_status()
{	
	srand(time(0));
	//string choices[] = {"WAITING","STOP"};
	int choices[] = { 1,2 };

	//vector<string> random;	
	vector<int> random;
	random.push_back(choices[rand() % 5]);
	for (int i = 0; i < random.size(); i++)
	{
		if (random[i] == 1)
		{
			return 1;
		}
		else if (random[i] == 2)
		{
			return 2;
		}
		
	}
	return 0;
}

void Admin::selectProcess(int count)
{
	for (int i = 0; i < count; i++) {
		int id = 0;
		cout << "Select the ID of the process to run: " << endl;
		cin >> id;
		for (int i = 0; i < processList.size();i++) {
			if (processList[i].getID() == id)
			{
				selectedList.push_back(processList[i]);
				
			}
			admin->run_process(selectedList);
		}
		
	
	}


}



void Admin::ProcessAdminMenu()
{
	cout << "\n--------------------------- Admin MENU ---------------------------------" << endl << endl;;
	
	int choice;
	while (true)
	{	
		cout << "Select what you want to perform: " << endl;
		cout << "1.create process\n 2.View processes\n 3.update process\n 4. delete proces\n 5. Quit\n" << endl<<endl;
		cin >> choice;
		if(choice < 0 || choice >5)
		{
			cout << "\nError: Invalid option Chosen: " << choice << " Try Again..\n";
		}

		else if (choice == 1)
		{
			int num;
			cout << endl << "\nEnter the number of processes you want to create: " << endl;
			cin >> num;
			for (int i = 0; i < num; i++)
			{
				admin->createProcess();
			}
		}
		else if (choice == 2)
		{
			admin->view_processes();
		}

		else if (choice == 3)
		{
			int count;
			cout << "\nEnter how many processes do you want to update: " << endl << endl;
			cin >> count;
			for (int i = 0; i < count; i++)
			{
				admin->updateProcess();
				break;
			}

		}

		else if (choice == 4)
		{	
			admin->view_processes();
			int index;
			cout << "Enter the index of the proces in the processList you want to delete: " << endl;
			cin >> index;
		
			admin->deleteProcess(index);
			//admin->deleteProcess();
		}

		else
			break;



	}
}

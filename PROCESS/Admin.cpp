
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


void Admin::updateProcess()
{

	for (auto& process : processList)
		{	
		int id;
		cout << "Enter the id of the process you want to update: " << endl;
		cin >> id;
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

void Admin::deleteProcess(int index)
{
	for (auto& process : processList)
		{
		int id;
		cin>>id;
		cout << "Enter the id of the process: " << endl;
		cin >> id;
			if (process.getiD() == id)
			{
				processList.erase(processList.begin()+index);
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


void Process::run_process(vector <Process> selectedList)
{

	cout << "Enter the Time Quantum for the processes: " << endl;
	cin >> quantum;


	while (true)
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

		
		for (int i = 0; i < selectedList.size(); i++)
			{
				while(selectedList[i].state != COMPLETED)
				{
					selectedList[i].currTime = selectedList[i].getBurstTime();
					if (selectedList[i].currTime < quantum)
					{	
						selectedList[i].timeInRunning += selectedList[i].currTime;
						selectedList[i].time_for_completion += selectedList[i].timeInRunning + selectedList[i].timeInWaiting + selectedList[i].timeInStopped;
						selectedList[i].currTime = 0;
						selectedList[i].state = COMPLETED;
						cout << "Process is Completed and the process completion time is " << selectedList[i].time_for_completion << endl;
			
					}

					else if (selectedList[i].currTime >= quantum)
					{	
						selectedList[i].timeInRunning += selectedList[i].currTime;
						selectedList[i].time_for_completion += selectedList[i].timeInRunning + selectedList[i].timeInWaiting + selectedList[i].timeInStopped;
						selectedList[i].currTime -= quantum;
						if (selectedList[i].currTime == 0)
						{
							selectedList[i].state = COMPLETED;
							cout << "Process is Completed and the process completion time is " << selectedList[i].time_for_completion << endl;
							break;
						}
						else
						{
							selectedList[i].state = get_random_status();
							if (selectedList[i].state == WAITING)
							{
								selectedList[i].timeInWaiting += 3;
								selectedList[i].time_for_completion += selectedList[i].timeInWaiting;

								selectedList[i].state = READY;
							}
							else if (selectedList[i].state == STOPPED)
							{
								selectedList[i].timeInStopped += 1;
								selectedList[i].time_for_completion += selectedList[i].timeInStopped;

								if (selectedList[i].currTime == 0)
								{
									selectedList[i].state = COMPLETED;
									cout << "Process is Completed and the process completion time is " << selectedList[i].time_for_completion << endl;

									break;
								}
								else
								{
									selectedList[i].state = READY;
								}
							}
						}
					
					}
				}
				cout << "The Waiting time for the first process is " << selectedList[i].timeInWaiting << endl;
				cout << "The Stopped time for the first process is " << selectedList[i].timeInStopped << endl;
				cout << "The Running time for the first process is " << selectedList[i].timeInRunning << endl;
			} 

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
	string choices[] = {"WAITING","STOP"};

	vector<string> random;	
	random.push_back(choices[rand() % 5]);
	for (int i = 0; i < random.size(); i++)
	{
		if (random[i] == "WAITING")
		{
			return 1;
		}
		else if (random[i] == "STOP")
		{
			return 2;
		}
	
	}
}

void Admin::selectProcess(int count)
{
	for (int i = 0; i < count; i++) {
		int id = 0;
		cout << "Select the ID of the process to run: " << endl;
		cin >> id;
		for (int i = 0; i < processList.size();i++) {
			if (processList[i].getiD() == id)
			{
				selectedList[i] = processList[i];
				
			}
			Process prt;
			prt.run_process(selectedList);
		}
		
	
	}


}



void Admin::ProcessAdminMenu()
{
	cout << "\n--------------------------- Admin MENU ---------------------------------"<<endl;
	cout << "Select what you want to perform: " << endl;
	cout << "01. View processes\n 2. create process\n 3.update process\n 4. delete proces\n 5. Quit\n";
	int choice;
	cout << "\tEnter a choice: " << endl;
	cin >> choice;
	while (choice != 5)
	{
		if (choice < 0 || choice >4)
		{
			cout << "\nError: Invalid option Chosen: " << choice << " Try Again..\n";
		}
		else if (choice == 1)
		{
			admin->view_processes();
		}
		else if (choice == 2)
		{
			admin->createProcess();
		}
		else if (choice == 3)
		{

			admin->updateProcess();
		}
		else if (choice == 4)
		{
			int index;
			cin >> index;
			admin->deleteProcess(index);
		}


		else
		{
			cout << "\nFunctionalities still yet to be updated" << endl;
		}
	}
}
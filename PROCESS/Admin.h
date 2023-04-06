#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

#include "Process.h"

using namespace std;

class Admin
{	

private:
	static Admin* admin;
	Admin();
	~Admin();	

public:
	queue<Process> process_queue;
	static Admin* getInstan()
	{
		if (admin == 0)
		{
			admin = new Admin();
		}
		return admin;
	}

	vector<Process> processList;
	vector<Process> selectedList;
	void ProcessAdminMenu(void);
	void view_processes();
	void createProcess();
	void displayProcess();
	void updateProcess();
	//void deleteProcess();
	void deleteProcess(int index);
	void selectProcess(int count);
	int get_random_status();
	void run_process(vector <Process> selectedList);
	

		
};

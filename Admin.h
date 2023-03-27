#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Admin
{

private:
	vector<Process> processList;
public:
	
	
	Admin();
	void ProcessAdminMenu(void);
	void view_processes();
	void createProcess();
	void displayProcess();
	void updateProcess(int id);
	void deleteProcess(int id, int index);
	~Admin();
};


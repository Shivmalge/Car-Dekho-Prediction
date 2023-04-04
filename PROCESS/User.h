#pragma once
#include <iostream>
#include <string.h>
#include "Admin.h"
using namespace std;

class User
{	
public:
	int cpucount;
	int processcount;

	const char* start = "Ready to run";
	const char* wait = " waiting";
	const char* stop = " Stopped";
	const char* complete = " Completed";
	const char* running = " Running";

	
	void process_status();
	void Process_log();
	void random_status_asignemt();
	bool Process_completioncheck();
	int quantum;
	void ProcessUserMenu(Admin* admin);
	void setQuatumTime(int Quantum);
	int getQuantumTime(void);
};


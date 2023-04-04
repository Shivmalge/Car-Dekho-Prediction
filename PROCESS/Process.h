
#pragma once
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Process
{	
public:

	enum ProcessState { READY, WAITING, STOPPED, COMPLETED };

	int ID;                  //process ID
	int num;
	int quantum;
	int rem_time;           //Remaining time
	string name;
	int burst;
	int state; // 1 = Ready to Run, 2 = Waiting, 3 = Stopped, 4 = Completed
	int currTime;
	int timeInReady;
	int timeInWaiting;
	int timeInStopped;
	int timeInRunning;
	int cpuId;

	int time_for_completion;
	int time_for_waiting;


	int time_spent[4] = { 0, 0, 0, 0 }; //{ready_to_run, waiting, stopped, completed}
	int time_cycle[2];

	Process();

	void setname(string name);
	string getname(void);

	void setBurstTime(int burst);
	int getBurstTime(void);

	
	//void setID(int ID);
	int getiD();
	//void setnoofprocess(int num);
	//int getnoofprocess(void);
	
	void run_process(vector <Process> processList);
	int get_random_status(void);
};

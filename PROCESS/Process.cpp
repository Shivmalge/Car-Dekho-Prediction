// Process.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "Process.h"
#include "Admin.h"


using namespace std;

Process::Process()
{
	ID = rand();
	burst = rand();
	num = 0;
	state = 1;
	timeRemaining = 0;
	timeInReady = 0;
	timeInWaiting = 0;
	timeInStopped = 0;
	int timeInRunning= 0;
	cpuId = -1;
}




int Process::getiD()
{
	return ID;
}

void Process::setname(string name)
{
	name = name;
}

string Process::getname()
{
	return name;
}

void Process::setBurstTime(int burst)
{
	burst = burst;
}

int Process::getBurstTime()
{
	return burst;
}







/*void Process::setnoofprocess(int num1)
{
	this->num = num1;
}

int Process::getnoofprocess()
{
	return this->num ;
}
*/


//Process will be inputed from user

/*void Process::Run_Process(void)
{	
	queue<Process> prcq;
	int num, quantum; // num = no of process, quantum = time quantum
	cout << "Enter the no of process: " << endl;
	cin >> num;
	cout << "Enter the time quantum: " << endl;
	cin >> quantum;
	Process prc;
	cout << "Enter the burst time: " << endl;
	for (int i = 0; i < num; i++)
	{
		cout << " Process " << i + 1 << endl;
		prc.ID = i + 1;
		cin >> prc.burst;
		cout << endl;
		prc.rem_time = prc.burst ;
		prc.status = "ready to run";
		prc.wait_time = 0;
		prcq.push(prc);
	}

	//Process time calculation
	int time = 0;
	while (!prcq.empty())
	{	
		Process curr = prcq.front();
		prcq.pop();
		if (curr.rem_time <= quantum) 
		{
			time += curr.rem_time;
			curr.status = "Completed";
			curr.wait_time = time - curr.burst;
			cout << "Process " << curr.ID << " completed at time " << time << endl;
			cout << "Process status is " << curr.status << " and waiting time is " << curr.wait_time << endl << endl;
		}

		else { //Process need more CPU time
			time += quantum;
			curr.rem_time -= quantum;
			curr.status = "Waiting";
			prcq.push(curr);
		}
	}
}
*/

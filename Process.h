#pragma once
#include<iostream>
#include<string.h>
using namespace std;

class Process
{
public:
	int ID;                  //process ID
	int num;
	int rem_time;           //Remaining time
	string status;          //Status of process
	int no_of_cycles_req; 
	string name;
	int burst;
	int timeToWait;

	Process();

	void setname(string name);
	string getname(void);

	void setBurstTime(int burst);
	int getBurstTime(void);



	
	//void setID(int ID);
	int getiD();;
	//void setnoofprocess(int num);
	//int getnoofprocess(void);
	Process() {

	}
};


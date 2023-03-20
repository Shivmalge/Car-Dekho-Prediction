#pragma once
#include<iostream>
#include<string.h>
using namespace std;

class Process
{
public:
    int name;  // process name
    int burst;    // burst time
    int rem;      // remaining time
    int wait_time;
    string status;
    int num_of_cycles_req;
    void run_process();
};


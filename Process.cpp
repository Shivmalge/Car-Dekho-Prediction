#include "Process.h"
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;


//Processes will be taken from the user
void Process::run_process() {
    queue<Process> prcq;
    int num, quantum;  // num = number of processes, quantum = time quantum
    cout << "\nEnter the number of processes: ";
    cin >> num;
    cout << "Enter the time quantum: ";
    cin >> quantum;
    cout << endl;
    Process prc;
    cout << "Enter process id and burst time for each process:\n";
    for (int i = 0; i < num; i++) {
        cout << "Process " << i + 1 << ":\n";
        prc.name = i + 1;
        cin >> prc.burst;
        cout << endl;
        prc.rem = prc.burst;
        prc.status = "Ready to run";
        prc.wait_time = 0;
        prcq.push(prc);
    }

    //Process time calculation
    int time = 0;
    while (!prcq.empty()) {
        Process curr = prcq.front();
        prcq.pop();
        if (curr.rem <= quantum) {  // process completes execution
            time += curr.rem;
            curr.status = "Completed";
            curr.wait_time = time - curr.burst;
            cout << "Process " << curr.name << " completed at time " << time << endl;
            cout << "Process status is " << curr.status << " and the waiting time is " << curr.wait_time << endl << endl;;
        }
        else {  // process needs more CPU time
            time += quantum;
            curr.rem -= quantum;
            prc.status = "waiting";
            prcq.push(curr);
        }
    }
}
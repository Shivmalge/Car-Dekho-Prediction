#include <iostream>
#include <string>
#include <vector>
#include "Process.cpp"

class ProcessSimulator
{

private:

    vector<Process> processes;
    vector<int> cpuStatus; // vector of status for each CPU (0 = free, 1 = busy)
    int timeSlice; // length of time slice in seconds

          // Traverse the list of processes and add any that are in Stopped state to the stoppedProcesses vector
    for (const Process& process : processes) {
        if (process.status == ProcessStatus::Stopped) {
            stoppedProcesses.push_back(process);
        }
    }

        return stoppedProcesses;
    }


    vector<Process> getStoppedProcesses()
    {
        vector<Process> stoppedProcesses;

        // Traverse the list of processes and add any that are in Stopped state to the stoppedProcesses vector
        for (const Process &process : processes)
        {
            if (process.status == ProcessStatus::Stopped)
            {
                stoppedProcesses.push_back(process);
            }
        }

        return stoppedProcesses;
    }

    void displayStoppedProcesses(const std::vector<Process> &stoppedProcesses)
    {
        if (stoppedProcesses.empty())
        {
            cout << "There are no stopped processes." << endl;
        }
        else
        {
            cout << "Stopped processes:" << endl;
            for (const Process &process : stoppedProcesses)
            {
                cout << "Process " << process.id << endl;
            }
        }
    }

    

public:
    void changeStoppedProcessStates()
    {
        // Get a list of stopped processes
        vector<Process> stoppedProcesses = getStoppedProcesses();

        // Display the list of stopped processes
        displayStoppedProcesses(stoppedProcesses);

        // Allow the user to change the state of each stopped process
        for (Process &process : stoppedProcesses)
        {
            cout << "Enter new status for process " << process.id << " (0 = Ready to Run, 3 = Completed): ";
            int newStatus;
            cin >> newStatus;

            switch (newStatus)
            {
            case 0:
                process.status = ProcessStatus::ReadyToRun;
                break;
            case 3:
                process.status = ProcessStatus::Completed;
                break;
            default:
                cout << "Invalid status. Process " << process.id << " state remains as Stopped." << endl;
            }
        }
    }
};

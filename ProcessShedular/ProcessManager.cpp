#include <iostream>
#include <string>
#include <vector>
#include "Process.cpp"

using namespace std;



class ProcessManager {
private:
    vector<ProcessEntity> processList;

public:
    void createProcess(string name, int requiredCycles, int waitCycles) {
        ProcessEntity process(name, requiredCycles, waitCycles);
        processList.push_back(process);
    }

    void updateProcess(int index, string name, int requiredCycles, int waitCycles) {
        if (index >= 0 && index < processList.size()) {
            processList[index].setName(name);
            processList[index].setRequiredCycles(requiredCycles);
            processList[index].setWaitCycles(waitCycles);
        }
    }

    void deleteProcess(int index) {
        if (index >= 0 && index < processList.size()) {
            processList.erase(processList.begin() + index);
        }
    }

    ProcessEntity& getProcess(int index) {
        return processList[index];
    }

    int getProcessCount() const {
        return processList.size();
    }

    vector<ProcessEntity> selectProcesses(vector<int> selectedIndexes) const {
        vector<ProcessEntity> selectedProcesses;
        for (auto index : selectedIndexes) {
            if (index >= 0 && index < processList.size()) {
                selectedProcesses.push_back(processList[index]);
            }
        }
        return selectedProcesses;
    }
};
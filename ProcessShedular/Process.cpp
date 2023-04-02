#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ProcessEntity {
private:
    string name;
    int requiredCycles;
    int waitCycles;
    

public:

    enum ProcessStatus { ReadyToRun, Waiting, Stopped, Completed };
    
    int id;
    int timeCycle;
    ProcessStatus status;
    int cpuId;

    


    ProcessEntity(std::string name, int requiredCycles, int waitCycles) {
        this->name = name;
        this->requiredCycles = requiredCycles;
        this->waitCycles = waitCycles;
    }

    string getName() const {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    int getRequiredCycles() const {
        return requiredCycles;
    }

    void setRequiredCycles(int requiredCycles) {
        this->requiredCycles = requiredCycles;
    }

    int getWaitCycles() const {
        return waitCycles;
    }

    void setWaitCycles(int waitCycles) {
        this->waitCycles = waitCycles;
    }
};


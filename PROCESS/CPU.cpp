
/*
#include "CPU.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

CPU::CPU()
{

}

void CPU::addCPU(vector<CPU>& cpuList) {
	CPU newCPU;
	cout << "Enter the name of the CPU: ";
	cin >> newCPU.name;
	cout << "Enter the clock speed of the CPU (in GHz): ";
	cin >> newCPU.clockSpeed;
	cout << "Enter the number of cores of the CPU: ";
	cin >> newCPU.cores;
	cpuList.push_back(newCPU);
	cout << "CPU added successfully." << endl;
}


void CPU::displayCPUs(vector<CPU>& cpuList) {
	cout << "CPU List:" << endl;
	for (int i = 0; i < cpuList.size(); i++) {
		cout << "Name: " << cpuList[i].name << " Clock Speed: " << cpuList[i].clockSpeed << "GHz Cores: " << cpuList[i].cores << endl;
	}
}



void CPU::updateCPU(vector<CPU>& cpuList, int index) {
	CPU updatedCPU;
	cout << "Enter the name of the CPU: ";
	cin >> updatedCPU.name;
	cout << "Enter the clock speed of the CPU (in GHz): ";
	cin >> updatedCPU.clockSpeed;
	cout << "Enter the number of cores of the CPU: ";
	cin >> updatedCPU.cores;
	cpuList[index] = updatedCPU;
	cout << "CPU updated successfully." << endl;
}


void CPU::deleteCPU(vector<CPU>& cpuList, int index) {
	cpuList.erase(cpuList.begin() + index);
	cout << "CPU deleted successfully." << endl;
}

void CPU::CPUfunc()
{
	vector<CPU> cpuList;
	int choice, index;
	do {
		cout << "Enter 1 to add a new CPU" << endl;
		cout << "Enter 2 to display the CPU list" << endl;
		cout << "Enter 3 to update a CPU" << endl;
		cout << "Enter 4 to delete a CPU" << endl;
		cout << "Enter 5 to exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			addCPU(cpuList);
			break;
		case 2:
			displayCPUs(cpuList);
			break;
		case 3:
			cout << "Enter the index of the CPU to update: ";
			cin >> index;
			if (index < 0 || index >= cpuList.size()) {
				cout << "Invalid index. Try again." << endl;
			}
			else {
				deleteCPU(cpuList, index);
			}
			break;
		case 4:
			updateCPU(cpuList, index);
			break;
		case 5:
			break;
		default:
			cout << "Invalid choice. Try again." << endl;
		}
	} while (choice != 5);
}

*/
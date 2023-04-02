#include <iostream>
#include <string>
using namespace std;

class CPUEntity {
private:
    std::string name;
    std::string manufacturer;
    int cores;
    int threads;
    double baseClockSpeed;
    double maxClockSpeed;
    double powerConsumption;
    double price;

public:
    CPUEntity(std::string name, std::string manufacturer, int cores, int threads, double baseClockSpeed, double maxClockSpeed, double powerConsumption, double price) {
        this->name = name;
        this->manufacturer = manufacturer;
        this->cores = cores;
        this->threads = threads;
        this->baseClockSpeed = baseClockSpeed;
        this->maxClockSpeed = maxClockSpeed;
        this->powerConsumption = powerConsumption;
        this->price = price;
    }

    std::string getName() const {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    string getManufacturer() const {
        return manufacturer;
    }

    void setManufacturer(string manufacturer) {
        this->manufacturer = manufacturer;
    }

    int getCores() const {
        return cores;
    }

    void setCores(int cores) {
        this->cores = cores;
    }

    int getThreads() const {
        return threads;
    }

    void setThreads(int threads) {
        this->threads = threads;
    }

    double getBaseClockSpeed() const {
        return baseClockSpeed;
    }

    void setBaseClockSpeed(double baseClockSpeed) {
        this->baseClockSpeed = baseClockSpeed;
    }

    double getMaxClockSpeed() const {
        return maxClockSpeed;
    }

    void setMaxClockSpeed(double maxClockSpeed) {
        this->maxClockSpeed = maxClockSpeed;
    }

    double getPowerConsumption() const {
        return powerConsumption;
    }

    void setPowerConsumption(double powerConsumption) {
        this->powerConsumption = powerConsumption;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        this->price = price;
    }
};
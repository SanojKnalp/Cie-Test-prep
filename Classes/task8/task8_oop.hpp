#ifndef SENSORDATA_HPP
#define SENSORDATA_HPP

#include <iostream>

class Sensor {
public:
    virtual ~Sensor() { std::cout << "Base Sensor destroyed\n"; }
    
    virtual double getAverage() const = 0;
};

class LidarSensor : public Sensor {
private:
    double* scans;
    size_t scanCount;
    
    mutable int readCount; 

public:
    LidarSensor(size_t count) : scanCount(count), scans(new double[count]), readCount(0) {
        for(size_t i=0; i<scanCount; ++i) scans[i] = 1.0; 
    }

    ~LidarSensor() {
        delete[] scans;
        std::cout << "Lidar destroyed\n";
    }

    // Copy Constructor
    LidarSensor(const LidarSensor& other) : scanCount(other.scanCount), readCount(other.readCount) {
        scans = new double[scanCount];
        for(size_t i=0; i<scanCount; ++i) scans[i] = other.scans[i];
    }

    // Copy Assignment Operator
    LidarSensor& operator=(const LidarSensor& other) {
        if(this != &other)
        {
             delete[] scans; 
        
            scanCount = other.scanCount;
            readCount = other.readCount;
            scans = new double[scanCount];
            for(size_t i=0; i<scanCount; ++i) scans[i] = other.scans[i];
        }
        return *this;
    }

    // Move Constructor
    LidarSensor(LidarSensor&& other) noexcept 
    : scans(other.scans), scanCount(other.scanCount), readCount(other.readCount) {
    other.scans = nullptr; // Neutralize the source
    other.scanCount = 0;
}

    // Move Assignment
    LidarSensor& operator=(LidarSensor&& other) noexcept {
        if(this != &other) {
            delete[] scans;
            scans = other.scans;
            scanCount = other.scanCount;
            readCount = other.readCount;
            other.scans = nullptr;
            other.scanCount = 0;
        }
        return *this;
    }

    LidarSensor operator+(const LidarSensor& other) const {
    LidarSensor result(this->scanCount + other.scanCount);
    // merge logic...
    return result; 
}

    size_t getScanCount() const {
        return scanCount;
    }

    double getAverage() const override {
        readCount++; 
        
        double sum = 0;
        for(size_t i=0; i<scanCount; ++i) sum += scans[i];
        return sum / scanCount;
    }
};

#endif


// BUG 4: Ownership was transferred, but the source was not neutralized.
// This will cause a double-free crash!
// BUG 5: Operator Overloading. This returns a reference to a local variable!
#ifndef SENSORDATA_HPP
#define SENSORDATA_HPP

#include <iostream>

class Sensor {
public:
    ~Sensor() { std::cout << "Base Sensor destroyed\n"; }
    
    virtual double getAverage() const = 0;
};

class LidarSensor : public Sensor {
private:
    double* scans;
    size_t scanCount;
    
    int readCount; 

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
        delete[] scans; 
        
        scanCount = other.scanCount;
        readCount = other.readCount;
        scans = new double[scanCount];
        for(size_t i=0; i<scanCount; ++i) scans[i] = other.scans[i];
        
        return *this;
    }

    // Move Constructor
    LidarSensor(LidarSensor&& other) noexcept : scans(other.scans), scanCount(other.scanCount), readCount(other.readCount) {
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

    LidarSensor& operator+(const LidarSensor& other) const {
        LidarSensor result(this->scanCount + other.scanCount);
        // ... (assume merging logic happens here) ...
        return result; 
    }

    size_t getScanCount() {
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


// BUG 1: Something is missing here that will cause a memory leak when 
// deleted via a base class pointer.
// BUG 2: Const correctness. The getAverage() function needs to increment this, 
// but the compiler throws an error.
// BUG 3: Rule of 5 critical omission here. What if a = a?
// BUG 4: Ownership was transferred, but the source was not neutralized.
// This will cause a double-free crash!
// BUG 5: Operator Overloading. This returns a reference to a local variable!
 // BUG 6: Const correctness. This getter shouldn't modify the object, 
// but it's missing the keyword that guarantees it.
// BUG 7: Related to Bug 2. Fix Bug 2 to make this compile.
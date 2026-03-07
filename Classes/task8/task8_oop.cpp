#include <cassert>
#include <iostream>
#include "task8_oop.hpp"



// Utility function to test const correctness (Bug 6)
size_t checkConst(const LidarSensor& sensor) {
    return sensor.getScanCount(); 
}

int main() {
    std::cout << "--- Starting Debugging Tests ---\n";

    // Test 1: 
    LidarSensor s1(5);
    assert(checkConst(s1) == 5);
    s1.getAverage(); // Should increment readCount
    
    // Test 2: 
    // If not fixed, s1 deletes its own memory, then reads garbage/crashes
    s1 = s1; 
    assert(s1.getScanCount() == 5);

    // Test 3: 
    {
        LidarSensor s2(10);
        LidarSensor s3 = std::move(s2);
        // When this block ends, s2 and s3 are destroyed. 
        // If s2.scans wasn't set to nullptr, it will double-free and crash.
    }

    // Test 4: 
    LidarSensor s4(2);
    LidarSensor s5(2);
    LidarSensor s6 = s4 + s5; 
    // If operator+ returns a reference, s6 will be initialized with garbage data.
    assert(s6.getScanCount() == 4);

    // Test 5: 
    Sensor* polySensor = new LidarSensor(100);
    delete polySensor; 

    std::cout << "Task 8: All bugs fixed! System is stable." << std::endl;
    return 0;
}
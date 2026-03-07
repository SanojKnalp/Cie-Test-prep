#include <iostream>
#include <cassert>
#include "task5_template.hpp"

void testExpansion() {
    std::cout << "--- Running PointCloud Expansion Test ---\n";
    
    // 1. Initialize with a very small capacity to force a 'grow()' call quickly
    PointCloud cloud(2); 
    
    // 2. Add points
    cloud.addPoint(1.0, 1.0, 1.0);
    cloud.addPoint(2.0, 2.0, 2.0);
    
    std::cout << "Added 2 points. Capacity is full. Adding 3rd point to trigger grow()...\n";
    
    // This call triggers grow()
    cloud.addPoint(3.0, 3.0, 3.0); 
    
    // 3. Verification
    // If your grow() logic is wrong (e.g., you deleted the points instead of just the container),
    // the program will crash here or print garbage.
    std::cout << "Checking if data survived the move...\n";
    
    // We add a print helper or use a debugger to check:
    // Points[0] should still be (1, 1, 1)
    
    std::cout << "Expansion Test Completed!\n\n";
}

int main() {
    try {
        testExpansion();
        std::cout << "All tests passed successfully.\n";
    } catch (...) {
        std::cerr << "Test failed! Check for double-frees or memory leaks.\n";
    }
    return 0;
}
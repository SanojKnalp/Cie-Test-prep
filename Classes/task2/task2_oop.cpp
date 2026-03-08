#include <iostream>
#include <cmath>
#include <vector>
#include "task2_oop_template.hpp"

// Add this to your test file to specifically target Assignment Operator logic
bool testAssignmentOperator() {
    System s1(5);
    s1.addHeavy(1, 10.0); // Weight: 98.1
    s1.addHeavy(2, 20.0); // Weight: 196.2

    System s2(5);
    s2.addHeavy(99, 5.0); // Existing data that SHOULD be deleted by s2 = s1

    // --- THE TEST: Assignment Operator ---
    s2 = s1; 

    // 1. Check for Shallow Copy (Shared Memory)
    // If your code uses 'list[i] = other.list[i]', both systems point to the same Particle.
    // In a deep copy, they should have DIFFERENT memory addresses.
    // We can't easily check addresses without getters, so we check behavior:
    
    s1.addHeavy(3, 30.0); // Add to s1 only. 

    double s1_weight = s1.calcTotalWeight(); // Should be 98.1 + 196.2 + 294.3 = 588.6
    double s2_weight = s2.calcTotalWeight(); // Should be 98.1 + 196.2 = 294.3

    // If s2_weight is 588.6 or 0, your assignment operator failed.
    if (std::abs(s2_weight - 294.3) > 0.01) {
        std::cout << "FAIL: s2 was affected by changes to s1 (Shallow Copy detected)!" << std::endl;
        return false;
    }

    // 2. The "Double Free" Trap
    // We force s1 to be destroyed. If s2 was sharing pointers with s1,
    // s2's pointers are now "dangling" (pointing to deleted memory).
    {
        System s3(2);
        s3.addHeavy(10, 1.0);
        s1 = s3; // This triggers the destructor logic for the old s1 particles
    } 

    // If s2 was sharing memory with the old s1, this call will likely 
    // crash the program or return garbage values.
    try {
        double final_check = s2.calcTotalWeight();
        if (std::abs(final_check - 294.3) > 0.01) throw std::runtime_error("Garbage data");
    } catch (...) {
        std::cout << "FAIL: s2 contains dangling pointers!" << std::endl;
        return false;
    }

    return true;
}

int main() {
    if (testAssignmentOperator()) {
        std::cout << "SUCCESS: Assignment Operator is robust!" << std::endl;
    } else {
        std::cout << "CRITICAL FAILURE: Your Assignment Operator is performing a shallow copy." << std::endl;
    }
    return 0;
}
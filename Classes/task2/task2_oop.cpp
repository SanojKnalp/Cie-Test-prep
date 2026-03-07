#include <iostream>
#include <cmath>
#include "task2_oop.hpp"
// Assuming the classes above are defined here...

bool testPrediction() {
    // --- YOUR PREDICTION ---
    // What is the value of 'result' after the operations below?
    // Enter your prediction for (Total Weight of s1) + (Total Weight of s2)
    double YOUR_PREDICTION = 0.0; 

    System s1(10);
    s1.addHeavy(1, 1.0); // Weight = 1.0 * 9.81 = 9.81
    s1.addHeavy(2, 2.0); // Weight = 2.0 * 9.81 = 19.62
    
    // Triggering the Copy Constructor
    System s2 = s1; 
    
    // Modify the original s1
    s1.addHeavy(3, 3.0); // Weight = 3.0 * 9.81 = 29.43

    // If Deep Copy works:
    // s1 weight = 9.81 + 19.62 + 29.43 = 58.86
    // s2 weight = 9.81 + 19.62 = 29.43
    
    double result = s1.calcTotalWeight() + s2.calcTotalWeight();

    // Use a small epsilon for double comparison
    return (std::abs(result - YOUR_PREDICTION) < 0.01);
}

int main() {
    if (testPrediction()) {
        std::cout << "EXAM READY: Prediction matched the polymorphic deep-copy result!" << std::endl;
    } else {
        std::cout << "NOT QUITE: Your prediction or your Rule of Three implementation is wrong." << std::endl;
        std::cout << "Check if s2.calcTotalWeight() was affected by s1.addHeavy()." << std::endl;
    }
    return 0;
}
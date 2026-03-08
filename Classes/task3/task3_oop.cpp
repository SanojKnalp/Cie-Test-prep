#include <iostream>
#include <cassert>
#include <algorithm>
#include "task3_oop_template.hpp"
// #include "task3_oop.hpp" // If your class is in this file, keep this line. 
// If your class is in the same file as main, DELETE this line.

// [Insert your ModernBuffer class definition here]

void run_buffer_test() {
    ModernBuffer b1(10);
    b1[0] = 42.0;

    // Test Copy
    ModernBuffer b2 = b1; 
    assert(b2[0] == 42.0);
    assert(b1.getData() != b2.getData()); // Verify Deep Copy
    std::cout << "Copy test passed!" << std::endl;

    // Test Move
    ModernBuffer b3 = std::move(b1);
    assert(b3[0] == 42.0);
    assert(b1.getData() == nullptr); // Verify Ownership Transfer
    std::cout << "Move test passed!" << std::endl;

    std::cout << "Task 3: Rule of 5 Passed!" << std::endl;
}

int main() {
    run_buffer_test();
    return 0;
}
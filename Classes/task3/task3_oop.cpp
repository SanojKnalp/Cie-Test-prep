#include <cassert>
#include "task3_oop.hpp"

void run_buffer_test() {
    ModernBuffer b1(10);
    b1[0] = 42.0;

    // Test Copy
    ModernBuffer b2 = b1; 
    assert(b2[0] == 42.0);
    assert(b1.getData() != b2.getData()); // Must be different memory addresses

    // Test Move
    ModernBuffer b3 = std::move(b1);
    assert(b3[0] == 42.0);
    assert(b1.getData() == nullptr); // Source must be nullified after move (p. 10)

    std::cout << "Task 1: Rule of 5 Passed!" << std::endl;
}
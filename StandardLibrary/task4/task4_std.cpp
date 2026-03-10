#include <iostream>
#include <cassert>
#include "task4_std_template.hpp"

// Initialize static tracker
int Matrix::active_allocations = 0;

int main() {
    {
        Matrix m1(2, 2);
        m1(0, 0) = 1.0; m1(0, 1) = 2.0;
        m1(1, 0) = 3.0; m1(1, 1) = 4.0;
        assert(Matrix::getActiveAllocations() == 1);

        // Test Copy Semantics
        Matrix m2 = m1;
        assert(Matrix::getActiveAllocations() == 2);
        assert(m2(1, 1) == 4.0);

        // Test Operator+= and +
        Matrix m3 = m1 + m2;
        assert(m3(0, 1) == 4.0);
        
        // Test Symmetric Friend Operators (Scalar Multiplication)
        Matrix m4 = m1 * 10.0;
        Matrix m5 = 10.0 * m1;
        assert(m4(1, 0) == 30.0);
        assert(m5(1, 0) == 30.0);

        // Test Copy-and-Swap Assignment
        m1 = m4; 
        assert(m1(0, 0) == 10.0);

        // Test Move Semantics
        Matrix m6 = std::move(m5);
        assert(m6(1, 1) == 40.0);
        // m5 should be in a valid but empty state (data_ = nullptr)
    }

    // If Rule of 5 is perfect, all dynamically allocated memory is freed!
    if (Matrix::getActiveAllocations() == 0) {
        std::cout << "SUCCESS: Matrix passed all logic and memory tests!" << std::endl;
    } else {
        std::cout << "MEMORY LEAK: " << Matrix::getActiveAllocations() << " matrices not freed!" << std::endl;
    }

    return 0;
}
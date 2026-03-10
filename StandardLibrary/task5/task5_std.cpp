#include <iostream>
#include <cassert>
#include "task5_std_template.hpp"

// Initialize static tracker
int Polynomial::poly_count = 0;

// Helper to double-check floating point math
bool isClose(double a, double b) { return std::abs(a - b) < 0.0001; }

int main() {
    {
        // p1 = 2x^1 + 3x^0
        Polynomial p1(1);
        p1[1] = 2.0; 
        p1[0] = 3.0;

        // p2 = 5x^3 + 1x^1
        Polynomial p2(3);
        p2[3] = 5.0; 
        p2[1] = 1.0; 
        p2[0] = 0.0;

        assert(Polynomial::getPolyCount() == 2);

        // Test Evaluation operator()
        // p1(2.0) = 2*(2) + 3 = 7.0
        assert(isClose(p1(2.0), 7.0));

        // Test Hard Compound Assignment (Reallocation required)
        p1 += p2; 
        // p1 is now degree 3: 5x^3 + 3x^1 + 3x^0
        assert(p1[3] == 5.0);
        assert(p1[1] == 3.0);
        assert(p1[0] == 3.0);
        
        // p1(2.0) = 5*(8) + 3*(2) + 3 = 40 + 6 + 3 = 49.0
        assert(isClose(p1(2.0), 49.0));

        // Test Binary + and Copy Semantics
        Polynomial p3 = p1 + p2;
        // p3 = 10x^3 + 4x^1 + 3x^0
        assert(p3[3] == 10.0);

        // Test Move Assignment via Copy-and-Swap
        Polynomial p4(0);
        p4 = std::move(p3);
        assert(p4[3] == 10.0);
    }

    if (Polynomial::getPolyCount() == 0) {
        std::cout << "SUCCESS: Polynomial passed all algebra and memory tests!" << std::endl;
    } else {
        std::cout << "MEMORY LEAK: " << Polynomial::getPolyCount() << " polynomials not freed!" << std::endl;
    }

    return 0;
}
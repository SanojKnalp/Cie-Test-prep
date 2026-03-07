#include <iostream>
#include <cassert>
#include "task2.hpp"

int main() {
    int r = 3, c = 4;
    int** myGrid = createMatrix(r, c);
    
    myGrid[2][3] = 42;
    assert(myGrid[2][3] == 42);
    
    std::cout << "Matrix access successful. Cleaning up...\n";
    deleteMatrix(myGrid, r);
    
    return 0;
}
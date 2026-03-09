#include <iostream>
#include <cassert>
#include "task2_std_template.hpp"

int main() {
    Zoo myZoo;
    
    myZoo.addDog();
    myZoo.addCat();
    myZoo.addDog();

    assert(myZoo.count() == 3);

    // Test Polymorphism + Iterators
    std::string sounds = myZoo.performConcert();
    // Should be "WoofMeowWoof"
    assert(sounds == "WoofMeowWoof");

    std::cout << "Task 2: Smart pointers and iterators working in harmony!" << std::endl;
    // Note: No 'delete' needed! Smart pointers clean up automatically. [cite: 49, 326]
    return 0;
}
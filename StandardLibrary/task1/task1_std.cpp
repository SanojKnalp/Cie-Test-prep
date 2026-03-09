#include <iostream>
#include <vector>
#include <cassert>
#include "task1_std_template.hpp"

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};

    // Test 1: Processing Even Numbers
    // factor = 10 -> 2 becomes 20, 4 becomes 40
    DataFilter::process(data, 10);
    
    assert(data[0] == 1);  // Odd
    assert(data[1] == 20); // Even * 10
    assert(data[2] == 3);  // Odd
    assert(data[3] == 40); // Even * 10
    assert(data[4] == 5);  // Odd

    // Test 2: Finding an element
    // First element in {1, 20, 3, 40, 5} greater than 25 is 40
    auto it = DataFilter::findFirstAbove(data, 25);
    
    if (it != data.end()) {
        assert(*it == 40);
        std::cout << "Find Success: Found " << *it << " at iterator position." << std::endl;
    } else {
        std::cout << "Find Failure: Element not found but should have been." << std::endl;
        return 1;
    }

    // Test 3: Finding non-existent element
    auto itFail = DataFilter::findFirstAbove(data, 100);
    assert(itFail == data.end());

    std::cout << "SUCCESS: All iterator tests passed!" << std::endl;
    return 0;
}
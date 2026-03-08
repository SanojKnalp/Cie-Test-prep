#include <cassert>
#include "task5_oop_template.hpp"
#include <iostream>
void run_tracker_test() {
    {
        ObjectTracker obj1(101);
        ObjectTracker obj2(102);
        assert(ObjectTracker::getGlobalCount() == 2);

        obj1.getId();
        obj1.getId();
        assert(obj1.getAccessCount() == 2); // Mutable worked in const function
    }
    // Objects out of scope, destructor should run
    assert(ObjectTracker::getGlobalCount() == 0);
    
    std::cout << "Task 3: Static/Mutable/Const Correctness Passed!" << std::endl;
}

int main()
{
    run_tracker_test();
    return 0;
}
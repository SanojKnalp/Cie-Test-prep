#include <cassert>
#include <iostream>
#include "task4_oop_template.hpp"

void run_scene_test() {
    SmartScene scene;
    scene.addShape(std::make_unique<Square>(10.0)); // Area 100
    scene.addShape(std::make_unique<Square>(5.0));  // Area 25
    
    assert(scene.getTotalArea() == 125.0);
    std::cout << "Task 2: Smart Pointer Polymorphism Passed!" << std::endl;
}

int main() {
    run_scene_test();
    return 0;
}
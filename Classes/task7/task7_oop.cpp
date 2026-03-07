#include <cassert>
#include <iostream>
#include "task7_oop.hpp"

int main() {
    // 1. Test Static Tracking & Creation
    assert(Polygon::getTotalPolygons() == 0);
    {
        Polygon p1(4);
        assert(Polygon::getTotalPolygons() == 1);
        
        // 2. Test Operator Overloading (Subscript)
        p1[0] = 10.5;
        assert(p1[0] == 10.5);
        
        // 3. Test Rule of 5: Copying
        Polygon p2 = p1; 
        assert(Polygon::getTotalPolygons() == 2);
        assert(p2[0] == 10.5);
        assert(&p1[0] != &p2[0]); // Must be deep copy

        // 4. Test Rule of 5: Moving
        Polygon p3 = std::move(p1);
        assert(Polygon::getTotalPolygons() == 3);
        assert(p3[0] == 10.5);
        // p1 should now be empty/nullified
    }
    assert(Polygon::getTotalPolygons() == 0); // Destructors should have run

    // 5. Test Polymorphism, Smart Pointers, and Mutable
    Scene myScene;
    auto poly = std::make_unique<Polygon>(4); // Area should be 4 * 2.5 = 10.0
    Polygon* rawPtr = poly.get(); // Keep a raw pointer just to check mutable counter
    
    myScene.addShape(std::move(poly));
    
    assert(myScene.getTotalSceneArea() == 10.0);
    assert(rawPtr->getComputationCount() == 1); // Mutable counter should have incremented
    
    std::cout << "Task 7: All tests passed successfully!" << std::endl;
    return 0;
}
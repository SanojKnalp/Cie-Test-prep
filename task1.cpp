#include <iostream>
#include <cassert>
#include "task1.hpp"

// A "Mock" shape to track if the destructor is actually called
class TestShape : public Shape {
public:
    static int dynamicObjectsCount; // Global tracker for this test
    TestShape() { dynamicObjectsCount++; }
    ~TestShape() { dynamicObjectsCount--; }
    void draw() override { std::cout << "Drawing TestShape\n"; }
};

int TestShape::dynamicObjectsCount = 0;

void testMemoryManagement() {
    std::cout << "--- Running Memory Test ---\n";
    {
        Scene myScene(5);
        myScene.addShape(new TestShape());
        myScene.addShape(new TestShape());
        
        assert(TestShape::dynamicObjectsCount == 2); 
        std::cout << "Objects in memory: " << TestShape::dynamicObjectsCount << "\n";
    } 
    // At this point, myScene goes out of scope and its destructor is called.
    
    assert(TestShape::dynamicObjectsCount == 0);
    std::cout << "Objects after Scene destruction: " << TestShape::dynamicObjectsCount << "\n";
    std::cout << "Memory Test Passed!\n\n";
}

int main() {
    testMemoryManagement();
    
    // Add more tests here for Topic 11 (Inheritance)
    return 0;
}
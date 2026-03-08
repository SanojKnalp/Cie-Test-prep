#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

// 1. Abstract Base Class (Topic 11)
class Shape {
public:
    // TODO: Add a virtual destructor
    virtual ~Shape() = default;
    
    // TODO: Add a pure virtual function 'double computeArea() const'
    virtual double computeArea() const = 0;
};

// 2. Concrete Class requiring Rule of 5
class Polygon : public Shape {
private:
    double* vertices; // Array of doubles (e.g., x1, y1, x2, y2...)
    size_t numVertices;
    
    // TODO: Declare a static integer 'totalPolygons' to track active instances
    static int totalPolygons;
    
    // TODO: Declare a mutable integer 'areaComputations' 
    mutable int areaComputations;

public:
    // Constructor
    Polygon(size_t count) : numVertices(count), vertices(new double[count]), /* init mutable */ {
        for(size_t i = 0; i < numVertices; ++i) vertices[i] = 0.0;
        // TODO: Increment static counter
    }

    // --- TODO: IMPLEMENT RULE OF 5 ---
    // 1. Destructor (Remember to decrement static counter)
    
    // 2. Copy Constructor (Deep copy, increment static counter)
    
    // 3. Copy Assignment Operator (Check self-assignment!)
    
    // 4. Move Constructor (Transfer ownership, increment static counter)
    
    // 5. Move Assignment Operator (Transfer ownership, clean up old)


    // --- TODO: OVERRIDES & CONST CORRECTNESS ---
    // Implement computeArea() overriding the base class.
    // Inside it, increment the mutable 'areaComputations' counter!
    // For this mock function, just return (numVertices * 2.5).


    // --- TODO: OPERATOR OVERLOADING (Lecture 6) ---
    // Overload the subscript operator [] to access 'vertices'. 
    // Provide both a non-const and a const version.


    // Getters
    size_t getVertexCount() const { return numVertices; }
    int getComputationCount() const { return areaComputations; }
    static int getTotalPolygons() { /* TODO: return static counter */ return 0; }
};

// TODO: Initialize the static 'totalPolygons' variable here (outside the class)


// 3. Manager Class using Smart Pointers (Lecture 5)
class Scene {
private:
    std::vector<std::unique_ptr<Shape>> shapes;

public:
    // TODO: Implement addShape which takes a unique_ptr<Shape> and moves it into the vector
    
    // TODO: Implement 'double getTotalSceneArea() const' which iterates through shapes
    // and calls computeArea() polymorphically.
};

#endif
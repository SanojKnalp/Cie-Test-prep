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
    Polygon(size_t count) : numVertices(count), vertices(new double[count]), areaComputations(0) {
        for(size_t i = 0; i < numVertices; ++i) vertices[i] = 0.0;
        // TODO: Increment static counter
        totalPolygons++;
    }

    // --- TODO: IMPLEMENT RULE OF 5 ---
    // 1. Destructor (Remember to decrement static counter)
    ~Polygon(){
        delete[] vertices;
        totalPolygons--;
    }
    
    // 2. Copy Constructor (Deep copy, increment static counter)
    Polygon(Polygon& other)
    {
        numVertices = other.numVertices;
        vertices = new double[numVertices];
        for(int i=0; i<numVertices; i++)
        {
            vertices[i] = other.vertices[i];
        }
        totalPolygons++;
        areaComputations = other.areaComputations;

    }
    
    // 3. Copy Assignment Operator (Check self-assignment!)
    Polygon& operator=(const Polygon& other)
    {
        if( this != &other)
        {
            delete[] vertices; // Clean up existing resource
            numVertices = other.numVertices;
            vertices = new double[numVertices];
            for (int i=0; i<numVertices; i++)
            {
                vertices[i] = other.vertices[i];
            }
            totalPolygons = other.totalPolygons;
            areaComputations = other.areaComputations;

        }
        return *this;
    }
    
    // 4. Move Constructor (Transfer ownership, increment static counter)
    Polygon(Polygon&& other) noexcept : numVertices(other.numVertices), vertices(other.vertices), areaComputations(other.areaComputations)
    {
        totalPolygons = other.totalPolygons;

        other.numVertices = 0;
        other.vertices = nullptr;
        other.areaComputations = 0;
        totalPolygons++;

    }
    
    // 5. Move Assignment Operator (Transfer ownership, clean up old)
    Polygon& operator=(Polygon&& other) noexcept
    {
        if( this != &other)
        {
            
            delete[] vertices; // Clean up current
            vertices = other.vertices; // Steal pointer
            numVertices = other.numVertices;
            areaComputations = other.areaComputations;


            other.vertices = nullptr;
            other.numVertices = 0;

        }
        return *this;
    }


    // --- TODO: OVERRIDES & CONST CORRECTNESS ---
    // Implement computeArea() overriding the base class.
    // Inside it, increment the mutable 'areaComputations' counter!
    // For this mock function, just return (numVertices * 2.5).
    double computeArea() const
    {
        areaComputations++;
        return numVertices*2.5;
    }


    // --- TODO: OPERATOR OVERLOADING (Lecture 6) ---
    // Overload the subscript operator [] to access 'vertices'. 
    // Provide both a non-const and a const version.
    double operator[](size_t index) const
    {
        return vertices[index];
    }

    double& operator[](size_t index)
    {
        return vertices[index];
    }


    // Getters
    size_t getVertexCount() const { return numVertices; }
    int getComputationCount() const { return areaComputations; }
    static int getTotalPolygons() {  return totalPolygons; }
};

// TODO: Initialize the static 'totalPolygons' variable here (outside the class)
int Polygon::totalPolygons = 0;
// 3. Manager Class using Smart Pointers (Lecture 5)
class Scene {
private:
    std::vector<std::unique_ptr<Shape>> shapes;

public:
    // TODO: Implement addShape which takes a unique_ptr<Shape> and moves it into the vector
    void addShape(std::unique_ptr<Shape> other)
    {
        shapes.push_back(std::move(other));
    }
    
    // TODO: Implement 'double getTotalSceneArea() const' which iterates through shapes
    // and calls computeArea() polymorphically.
    double getTotalSceneArea() const 
    {
        double totalarea = 0;
        for(const auto& shape : shapes)
        {
            totalarea+=shape->computeArea();
        }
        return totalarea;
    }
};

#endif



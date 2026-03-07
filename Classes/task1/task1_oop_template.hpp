#include <iostream>

class Shape {
protected:
    int id;
public:
    Shape(int i) : id(i) {}
    virtual ~Shape() { std::cout << "Shape " << id << " deleted\n"; }
    virtual double getArea() const = 0; 
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(int i, double r) : Shape(i), radius(r) {}
    double getArea() const override { return 3.14 * radius * radius; }
};

class Scene {
private:
    Shape** shapes;
    int count;
    int capacity;

public:
    Scene(int cap) : capacity(cap), count(0) {
        shapes = new Shape*[capacity];
    }

    // TASK 1: Implement the Rule of Three (Copy Constructor)
    // You must create NEW Circle objects for the new scene!
    Scene(const Scene& other) : capacity(other.capacity), count(other.count) {
        shapes = new Shape*[capacity];
        for(int i = 0; i < count; ++i) {
            // TRICKY: How do you copy a polymorphic object? 
            // For the exam, assume we only have Circles for now.
            // In a real exam, you might need a virtual 'clone()' method.
            // Let's just create a new Circle with same data for this exercise.
            // (Assume all shapes in 'other' are Circles)
        }
    }

    // TASK 2: Destructor
    ~Scene() {
        for(int i = 0; i < count; ++i) {
            delete shapes[i];
        }
        delete[] shapes;
    }

    void addCircle(int id, double r) {
        if (count < capacity) {
            shapes[count++] = new Circle(id, r);
        }
    }

    double getTotalArea() const {
        double total = 0;
        for(int i = 0; i < count; ++i) {
            total += shapes[i]->getArea(); // Polymorphic call
        }
        return total;
    }
};
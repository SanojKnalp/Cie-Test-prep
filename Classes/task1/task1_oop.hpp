#include <iostream>

class Shape {
protected:
    int id;
public:
    Shape(int i) : id(i) {}
    virtual ~Shape() { std::cout << "Shape " << id << " deleted\n"; }
    virtual double getArea() const = 0; 
    int getid() const { return id; }
    virtual double getRadius() const =0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(int i, double r) : Shape(i), radius(r) {}
    double getArea() const override { return 3.14 * radius * radius; }
    double getRadius() const { return radius;}
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
    Scene(const Scene& other) : capacity(other.capacity), count(0) {
        shapes = new Shape*[capacity];
        for(int i = 0; i < count; ++i) {
                int id_ = other.shapes[i]->getid();
                double radius_ = other.shapes[i]->getRadius();
                addCircle(id_, radius_);
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
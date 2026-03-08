#include <vector>
#include <memory>

class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0; // Pure virtual (Abstract)
};

class Square : public Shape {
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override { return side * side; }
};

class SmartScene {
private:
    // Use unique_ptr to follow "Best Practices" (Lecture 5, p. 11)
    std::vector<std::unique_ptr<Shape>> elements;

public:
    void addShape(std::unique_ptr<Shape> s) {
        elements.push_back(std::move(s));
    }

    double getTotalArea() const {
        double area = 0.0;
        for (int i=0; i< elements.size(); i++)
        {
            area+= elements[i]->area();
        }
        return area;
    }
};
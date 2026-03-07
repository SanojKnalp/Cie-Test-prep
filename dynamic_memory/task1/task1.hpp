// task1.hpp
class Shape {
public:
    virtual ~Shape() {} // Why is this virtual?
    virtual void draw() = 0; 
};

class Circle : public Shape {
public:
    void draw() override { /* Drawing logic */ }
};

class Scene {
private:
    Shape** shapes; // Dynamic array of pointers to Shapes
    int count;
    int capacity;

public:
    Scene(int cap) : capacity(cap), count(0) {
        // TODO: Allocate the array of pointers on the heap
        shapes = new Shape*[capacity];
    }

    ~Scene() {
        // TODO: Clean up every individual shape AND the array itself
        for (int i = 0; i<count; i++)
        {
            delete shapes[i];
        }
        delete[] shapes;
    }

    void addShape(Shape* s) {
        if (count < capacity) {
            shapes[count++] = s;
        }
    }
};
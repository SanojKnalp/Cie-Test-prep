#include <iostream>

class Vector2D {
private:
    double coords[2];

public:
    Vector2D(double x, double y) {
        coords[0] = x; coords[1] = y;
    }

    // 1. Overload + operator (Member function)
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(coords[0]+other.coords[0], coords[1]+other.coords[1]);
    }

    // 2. Overload Subscript [] (Lecture 6, p. 9)
    double& operator[](size_t index) {
        return coords[index];
    }
    
    const double& operator[](size_t index) const {
        return coords[index];
    }

    // 3. Overload << as a Friend Function (Lecture 6, p. 9)
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
        os << "(" << v.coords[0] << ", " << v.coords[1] << ")";
        return os;
    }
};
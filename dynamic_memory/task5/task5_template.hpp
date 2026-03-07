#include <iostream>

class PointCloud {
private:
    double** points; // Array of pointers to double[3]
    int capacity;
    int count;

    void grow() {
        std::cout << "Growing capacity from " << capacity << " to " << capacity * 2 << "\n";
        
        // TODO: Implement the growth logic here
        // 1. Allocate new double** with 2 * capacity
        // 2. Copy existing pointers to the new array
        // 3. Delete the OLD array (the container), but NOT the points themselves
        // 4. Update points pointer and capacity
    }

public:
    PointCloud(int initialCap) : capacity(initialCap), count(0) {
        points = new double*[capacity];
    }

    ~PointCloud() {
        for (int i = 0; i < count; ++i) {
            delete[] points[i]; // Delete each [x,y,z] array
        }
        delete[] points; // Delete the array of pointers [cite: 121]
    }

    void addPoint(double x, double y, double z) {
        if (count == capacity) {
            grow();
        }
        points[count] = new double[3]{x, y, z};
        count++;
    }
};
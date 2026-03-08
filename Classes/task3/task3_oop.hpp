#include <iostream>
#include <algorithm>

class ModernBuffer {
private:
    double* data;
    size_t size;

public:
    ModernBuffer(size_t s) : size(s), data(new double[s]) {
        for(size_t i=0; i<size; ++i) data[i] = 0.0;
    }

    // --- IMPLEMENT THE RULE OF FIVE ---
    
    // 1. Destructor
    ~ModernBuffer() { 
        delete[] data;
        size = 0;
     }

    // 2. Copy Constructor (Deep Copy)
    ModernBuffer(const ModernBuffer& other) : size(other.size) {
        data = new double[size];
        for(int i=0; i<size; i++)
        {
            data[i] = other.data[i];
        }
     }

    // 3. Copy Assignment Operator
    ModernBuffer& operator=(const ModernBuffer& other) { 
        if( this != &other)
        {
            size = other.size;
            for (int i=0; i<size; i++)
            {
                data[i] = other.data[i];
            }

        }
        return *this;
     }

    // 4. Move Constructor (Lecture 5, p. 10 - Transfer ownership)
    ModernBuffer(ModernBuffer&& other) noexcept 
        : data(other.data), size(other.size) { 
        other.data = nullptr;                 
        other.size = 0;
    }

    // 5. Move Assignment Operator
    ModernBuffer& operator=(ModernBuffer&& other) noexcept { 
        if(this != &other)
        {
            delete[] data;
            size = other.size;
            data = other.data;
            other.size = 0;
            other.data = nullptr;
        }
        return *this;
     }

    double& operator[](size_t idx) { return data[idx]; }
    size_t getSize() const { return size; }
    double* getData() const { return data; }
};
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
    ~ModernBuffer() { /* TODO */ }

    // 2. Copy Constructor (Deep Copy)
    ModernBuffer(const ModernBuffer& other) { /* TODO */ }

    // 3. Copy Assignment Operator
    ModernBuffer& operator=(const ModernBuffer& other) { /* TODO */ }

    // 4. Move Constructor (Lecture 5, p. 10 - Transfer ownership)
    ModernBuffer(ModernBuffer&& other) noexcept { /* TODO */ }

    // 5. Move Assignment Operator
    ModernBuffer& operator=(ModernBuffer&& other) noexcept { /* TODO */ }

    double& operator[](size_t idx) { return data[idx]; }
    size_t getSize() const { return size; }
    double* getData() const { return data; }
};
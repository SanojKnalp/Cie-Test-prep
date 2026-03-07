#include <iostream>

class BaseBuffer {
protected:
    int* data;
    int size;
public:
    BaseBuffer(int s) : size(s) {
        data = new int[size];
        std::cout << "Base Constructed\n";
    }
    // TRAP: Missing something here? (Topic 11)
    ~BaseBuffer() {
        delete[] data;
        std::cout << "Base Destructed\n";
    }
};

class DerivedBuffer : public BaseBuffer {
private:
    int* secondaryData;
public:
    DerivedBuffer(int s) : BaseBuffer(s) {
        secondaryData = new int[size];
        std::cout << "Derived Constructed\n";
    }
    ~DerivedBuffer() {
        delete[] secondaryData;
        std::cout << "Derived Destructed\n";
    }
};

// TRICKY FUNCTION (Topic 4: By Value)
void processBuffer(BaseBuffer b) {
    std::cout << "Processing...\n";
}
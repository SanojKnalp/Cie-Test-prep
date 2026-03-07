#include <iostream>
//Fix the bug
class BaseBuffer {
protected:
    int* data;
    int size;
public:
    BaseBuffer(int s) : size(s) {
        data = new int[size];
        std::cout << "Base Constructed\n";
    }
    virtual ~BaseBuffer() {
        delete[] data;
        std::cout << "Base Destructed\n";
    }

    BaseBuffer(const BaseBuffer& other)
    {
        data = new int(other.size);
        for(int i=0; i<other.size; i++)
        {
            data[i] = other.data[i];
        }
        std::cout << "Base Deep Copied\n";
    }
    BaseBuffer& operator=(const BaseBuffer& other)
    {
        if(this != &other)
        {
            delete[] data;
            data = new int(other.size);
            for(int i=0; i<other.size; i++)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
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

void processBuffer(BaseBuffer b) {
    std::cout << "Processing...\n";
}
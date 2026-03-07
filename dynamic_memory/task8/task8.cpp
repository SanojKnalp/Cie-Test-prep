#include <iostream>
// Adjust the code such that the test passes
class Base {
public:
    virtual int getId() { return 1; }
    virtual ~Base() {}
};

class Derived : public Base {
public:
    int getId() override { return 2; }
};

// 1. Pointer passed by value
void alpha(Base* b) {
    b = new Derived(); 
}

// 2. Pointer passed by address (pointer-to-pointer)
void beta(Base** b) {
    delete *b;
    *b = new Derived();
}

// 3. Object passed by value (Base type)
int gamma(Base& b) {
    return b.getId();
}

bool testPrediction() {

    Base* obj = new Base(); // Starts as a Base object (ID: 1)
    
    // Step 1: alpha
    alpha(obj);
    int v1 = obj->getId();

    // Step 2: beta
    beta(&obj);
    int v2 = obj->getId();

    // Step 3: gamma 
    // Note: We are passing the object pointed to by 'obj' (which is now Derived)
    int v3 = gamma(*obj);

    // Encoding the result: (v1 * 100) + (v2 * 10) + v3
    int finalResult = (v1 * 100) + (v2 * 10) + v3;

    // Cleanup
    delete obj;

    return (finalResult == 122);
}

int main() {
    if (testPrediction()) {
        std::cout << "Correct! You are a master of C++ memory and polymorphism." << std::endl;
    } else {
        std::cout << "Incorrect. One of the three steps tripped you up!" << std::endl;
    }
    return 0;
}
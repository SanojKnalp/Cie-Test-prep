#include "task4_template.hpp"

int main() {
    std::cout << "--- Starting Test ---\n";
    {
        DerivedBuffer d(10);
        processBuffer(d); // What happens here?
    } 
    std::cout << "--- Test Finished ---\n";
    return 0;
}
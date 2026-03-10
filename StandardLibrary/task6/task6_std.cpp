#include <iostream>
#include <cassert>
#include "task6_std.hpp"

int main() {
    // 1. Test Compile-Time Type Traits
    assert(IsPointer<int>::value == false);
    assert(IsPointer<double*>::value == true);

    Pipeline pipe;

    // 2. Test Standard Template Push
    pipe.push(42);
    pipe.push(3.14);

    // 3. Test Full Specialization (bool)
    pipe.push(true);
    pipe.push(false);

    // 4. Test Partial Specialization (pointers)
    int secret = 99;
    int* ptr = &secret;
    pipe.push(ptr); // Should use DataNode<T*>

    // Verify early state
    std::string early_state = pipe.process();
    // Expected: "42 | 3.14 | TRUE | FALSE | 99 | "
    std::cout << "Pipeline State 1: " << early_state << "\n";
    assert(early_state.find("TRUE") != std::string::npos);
    assert(early_state.find("99") != std::string::npos);

    // 5. Test Variadic Templates
    Pipeline variadic_pipe;
    variadic_pipe.push_all("Start", 100, false, &secret);
    
    assert(variadic_pipe.size() == 4);
    std::string final_state = variadic_pipe.process();
    
    // Expected: "Start | 100 | FALSE | 99 | "
    std::cout << "Pipeline State 2: " << final_state << "\n";
    assert(final_state == "Start | 100 | FALSE | 99 | ");

    std::cout << "\nSUCCESS: Advanced Templates, Traits, and Polymorphism mastered!" << std::endl;
    return 0;
}
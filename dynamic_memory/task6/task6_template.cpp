#include <iostream>

// This is the function from the exercise
void modifyPointer(int* p) {
    p = new int(50); 
    *p = 500;
    // Note: The memory allocated here (the '500') is never deleted!
}

bool testPrediction() {
    // --- YOUR TASK: Put your predicted output here ---
    int YOUR_PREDICTION = 0; 
    
    // --- The logic to test ---
    int* ptr = new int(10);
    modifyPointer(ptr);
    
    int result = *ptr;
    delete ptr; // Cleanup
    
    return (result == YOUR_PREDICTION);
}

int main() {
    if (testPrediction()) {
        std::cout << "Correct! You correctly identified how pass-by-value works for pointers." << std::endl;
    } else {
        std::cout << "Incorrect. Try tracing the memory one more time!" << std::endl;
    }
    return 0;
}
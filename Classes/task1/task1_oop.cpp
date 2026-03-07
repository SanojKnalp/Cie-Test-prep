#include <iostream>
#include "task1_oop.hpp"
void analyzeScene(Scene s) {
    std::cout << "Area: " << s.getTotalArea() << " ";
}

bool testPrediction() {
    // --- YOUR PREDICTION ---
    // What will be the value of 'result'? 
    // Think about how many 'Shape X deleted' messages appear 
    // and what the final area is.
    double YOUR_PREDICTION = 314.0;

    Scene myScene(5);
    myScene.addCircle(1, 10.0); // Area = 314
    analyzeScene(myScene); 
    
    double result = myScene.getTotalArea();
    return (result == YOUR_PREDICTION);
}

int main() {
    if (testPrediction()) {
        std::cout << "Success! You mastered the Scene Manager." << std::endl;
    } else {
        std::cout << "Failed. Hint: Did 'analyzeScene' destroy your original shapes?" << std::endl;
    }
    return 0;
}
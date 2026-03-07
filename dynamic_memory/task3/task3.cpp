//Fix the bug
#include <iostream>

int* createValues() {
    int* localArr = new int[3];
    localArr[0] = 1;
    localArr[1] = 2;
    localArr[2] = 3;
    return localArr; 
}

int main() {
    int* data = createValues();
    std::cout << data[0];
    return 0;
}
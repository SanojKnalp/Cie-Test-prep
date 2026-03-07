//Fix the bug
#include <iostream>
int* createValues() {
    int localArr[3] = {1, 2, 3};
    return localArr; 
}

int main() {
    int* data = createValues();
    std::cout << data[0];
    return 0;
}
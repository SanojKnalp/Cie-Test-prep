#include <iostream>

int main()
{
    int i=3;
    int* a = &i;
    int&b = i;
    int j = i;
    i = -2;
    std::cout << a-&j << std::endl;
    std::cout << *a-j << std::endl;
    std::cout << b-j << std::endl;
    return 0;
 }
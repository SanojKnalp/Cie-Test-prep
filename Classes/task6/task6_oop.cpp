#include <cassert>
#include "task6_oop_template.hpp"

void run_operator_test() {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);

    Vector2D v3 = v1 + v2; // Testing +
    assert(v3[0] == 4.0 && v3[1] == 6.0); // Testing []

    v3[0] = 10.0; // Testing non-const []
    assert(v3[0] == 10.0);

    std::cout << "Task 4: Operator Overloading Passed!" << std::endl;
}

int main()
{
    run_operator_test();
    return 0;
}
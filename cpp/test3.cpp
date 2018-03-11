#include "func.h"
#include <iostream>

int main()
{
    std::cout << " func in test3.cpp" << std::endl;
    // inf IEEE 754
    std::cout << (float)1 / (float)0 << std::endl;
    // division-by-zero is undefined behavior
    std::cout << (int) 1 / (int) 0 << std::endl;
    return 0;
}

#include "func.h"
#include <iostream>

namespace test
{
void func()
{
    std::cout << " func in test3.cpp" << std::endl;
    std::cout << (float) 1 / (float) 0 << std::endl;
//     std::cout << (int) 1 / (int) 0 << std::endl; // it raise SIGNAL (crash)
}

} // namespace test

int main()
{
    test::func();
    return 0;
}


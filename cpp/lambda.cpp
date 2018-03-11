#include <functional>
#include <iostream>

int main()
{
    static int a = 100;

    auto f = [](int b) { return a + b; };
    auto f2 = [=](int b) { return a + b; };
    a = 10;
    // 10 + 10 = 20 (referenced a directly via static)
    std::cout << f(10) << std::endl;
    std::cout << f2(10) << std::endl;

    // cannot captured since a is static
    //auto f3 = [&a](int b) { return a + b; };
    //std::cout << f3(10) << std::endl;
    // cannot captured since a is static
    //auto f4 = [a](int b) { return a + b; };
    //std::cout << f4(10) << std::endl;

    std::function<int(int)> factorial = [&factorial](auto n) -> auto {
        return n == 0 ? 1 : n * factorial(n - 1);
    };

    // 3628800
    std::cout << factorial(10) << std::endl;


    // uninitialized variable is used with its own initialization
    // segmentation fault
    //std::function<int(int)> factorial2 = [factorial2](int n) -> int {
    //    return n == 0 ? 1 : n * factorial2(n - 1);
    //};
    //std::cout << factorial2(10) << std::endl;

    return 0;
}

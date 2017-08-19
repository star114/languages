#include <functional>
#include <iostream>

int main()
{
    static int a = 100;

    auto f = [](int b) { return a + b; };
    //auto f = [=](int b) { return a + b; };
    //auto f = [&a](int b) { return a + b; };
    a = 10;

    std::cout << f(10) << std::endl;

    std::function<int(int)> factorial = [&factorial](int n) -> int {
        return n == 0 ? 1 : n * factorial(n - 1);
    };

    std::cout << factorial(10) << std::endl;

    //    std::function<int(int)> factorial2 = [factorial2](int n) -> int {
    //        return n == 0 ? 1 : n * factorial2(n - 1);
    //    };
    //
    //    std::cout << factorial2(10) << std::endl;

    return 0;
}

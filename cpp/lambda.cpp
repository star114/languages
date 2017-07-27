#include <iostream>

int main()
{
    static int a = 100;

    auto f = [](int b) { return a + b; };
    //auto f = [=](int b) { return a + b; };
    //auto f = [&a](int b) { return a + b; };
    a = 10;

    std::cout << f(10) << std::endl;

    return 0;
}

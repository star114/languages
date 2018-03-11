#include <functional>
#include <iostream>
#include <memory>

int f(int a, int b, int c)
{
    return a + b + c;
}

int main()
{
    using namespace std::placeholders;

    int n = 7;
    // set by value
    auto f1 = std::bind(f, _2, _1, n);
    // it doesn't affect function binded value.
    n = 10;

    // 10 (2 + 1 + 7)
    std::cout << f1(1, 2, 100, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std::endl;
    // 110 (3 + 100 + 7)
    std::cout << f1(100, 3) << std::endl;

    return 0;
}

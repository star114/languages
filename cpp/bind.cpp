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
    auto f1 = std::bind(f, _2, _1, n);
    n = 10;
    std::cout << f1(1, 2, 100, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std::endl;

    return 0;
}

#include <iostream>
#include <utility>
#include <typeinfo>

int y(int& a)
{
    std::cout << __PRETTY_FUNCTION__ << typeid(a).name() << std::endl;
    return 1;
}

int y(int&& b)
{
    std::cout << __PRETTY_FUNCTION__ << typeid(b).name() << std::endl;
    return 2;
}

// universal reference
template <class T>
int f(T&& x)
{
    std::cout << __PRETTY_FUNCTION__ << typeid(x).name() << std::endl;
    // force to call the function passing lvalue reference
    return y(x);
}

template <class T>
int g(T&& x)
{
    std::cout << __PRETTY_FUNCTION__ << typeid(x).name() << std::endl;
    // force to call the function passing rvalue reference using move
    return y(std::move(x));
}

template <class T>
int h(T&& x)
{
    std::cout << __PRETTY_FUNCTION__ << typeid(x).name() << std::endl;
    // forward x type to y function.
    return y(std::forward<T>(x));
}

int main()
{
    int i = 10;
    // 1 called int y(int&)
    std::cout << f(i) << std::endl;
    // 1 called int y(int&)
    std::cout << f(20) << std::endl;
    // 2 called int y(int&&)
    std::cout << g(i) << std::endl;
    // 2 called int y(int&&)
    std::cout << g(20) << std::endl;
    // 1 called int y(int&)
    std::cout << h(i) << std::endl;
    // 2 called int y(int&&)
    std::cout << h(20) << std::endl;
    return 0;
}

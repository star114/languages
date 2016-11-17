#include <sstream>
#include <iostream>
#include <string>
#include <array>
#include <typeinfo>

template <typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept
{
    return N;
}

template <typename T>
void f(T& param)
{
    std::cout << "f(" << typeid(T).name() << " " << param << ") called" << std::endl;
}

void someFunc(int, double)
{
    std::cout << "someFunc() called" << std::endl;
}

template<typename T>
void f1(T param)
{
    std::cout << "f1(" << typeid(T).name() << " " << param << ") called" << std::endl;
}

template<typename T>
void f2(T& param)
{
    std::cout << "f2(" << typeid(T).name() << " " << param << ") called" << std::endl;
}

void foo(int a)
{
    static int t = 100;
    std::cout << t++ << std::endl;
}
int main()
{
//    const char * t = NULL;
//    int n = 12;
//    std::stringstream ss;
//    ss << n;
//    std::cout << ss.str() << std::endl;
//    char * s = const_cast<char*>("hi");
//    int u = 0;
//    ss >> u;
//    std::cout << s << u<< std::endl;
//    std::stringstream ss2;
//    ss2 << "test" << std::endl;
//    std::cout << ss2.str().c_str();
//
//    foo(1);
//    foo(1);
//    foo(1);
//

    int keyVals[] = {1,3,5,7,9,11,13};
    std::array<int, arraySize(keyVals)> mappedVals;
    std::cout << mappedVals.size() << std::endl;

    int x = 27;
    const int cx = x;
    const int& rx = x;

    f(x);
    f(cx);
    f(rx);

    char y = 'a';
    const char cy = y;
    const char& ry = y;

    f(y);
    f(cy);
    f(ry);

    f1(someFunc);
    f2(someFunc);

    return 0;
}

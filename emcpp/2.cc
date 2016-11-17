#include <iostream>
#include <typeinfo>

template <typename T>
void f(T param)
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

template<typename T>
void f3(std::initializer_list<T> iniList)
{

}

int main ()
{
    auto x = 27;
    const auto cx = x;
    const auto& rx = x;
    
    f(x);
    f(cx);
    f(rx);

    auto&& uref1 = x;
    auto&& uref2 = cx;
    auto&& uref3 = 27;

    f(uref1);
    f(uref2);
    f(uref3);

    auto func1 = someFunc;
    auto& func2 = someFunc;

    f1(func1);
    f1(func2);
    f2(func1);
    f2(func2);

    auto x1 = 27;
    auto x2(27);
    auto x3 = {27};
    auto x4{27};

    std::cout << x1 << x2 << std::endl;
    //std::cout << x3 << x4 << std::endl;
   
    auto x5 = {1,2,3};
    //f1(x5);
    f3(x5);
    return 0;
}

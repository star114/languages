#include <iostream>

namespace global {

inline
namespace a {
void f()
{
    std::cout << "a::f()" << std::endl;
}
}

//inline
namespace b {
void f()
{
    std::cout << "b::f()" << std::endl;
}
}

void func()
{
    f();
}
}

int main()
{
    global::func();
    return 0;
}


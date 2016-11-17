#include <iostream>

template<typename T>
void foo(T& x)
{
}


int main()
{
    int x = 42;
    foo(x);
    int const cx = x;
    foo(cx);
    int const& rx = &x;
    foo(rx);

}

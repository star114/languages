#include <iostream>

class X
{
public:
    virtual ~X() = default;
};

int main()
{
    X x;

    // This will not fire even in GCC 4.7.2 if the destructor is
    // explicitly marked as noexcept(true)
    static_assert(noexcept(x.~X()), "Ouch!");
}

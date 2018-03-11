#include <iostream>

class X
{
public:
    X() = default;
    virtual ~X() = default;
    virtual void Test()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

int main()
{
    X x;

    // This will not fire even in GCC 4.7.2 if the destructor is
    // explicitly marked as noexcept(true)
    // default destructor is automatically generated with noexcept keyword.
    static_assert(noexcept(x.~X()), "Ouch!");

    // it is fired.
    //static_assert(noexcept(x.Test()), "Oops!");
}

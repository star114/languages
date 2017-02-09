#include <iostream>

class Base
{
public:
    Base() { std::cout << "Base::Base()" << std::endl; }
    virtual ~Base() { std::cout << "Base::~Base()" << std::endl; }
};

class Derived : public Base
{
public:
    Derived() : Base() { throw; std::cout << "Derived::Derived()" << std::endl; }
    virtual ~Derived() { std::cout << "Derived::~Derived()" << std::endl; }
};

class test
{
public:
    test() { std::cout << "test::test()" << std::endl; }
    virtual ~test() { std::cout << "test::~test()" << std::endl; }
};

int main()
{
    {
        Derived d;
    }
    return 0;
}

#include <exception>
#include <iostream>

class test {
public:
    test() { std::cout << "test::test()" << std::endl; }
    virtual ~test() { std::cout << "test::~test()" << std::endl; }
};

class Base {
public:
    Base() { std::cout << "Base::Base()" << std::endl; }
    virtual ~Base() { std::cout << "Base::~Base()" << std::endl; }
};

class Derived : public Base {
public:
    Derived()
        : Base()
        , t(new test())
    {
        throw std::exception();
        std::cout << "Derived::Derived()" << std::endl;
    }
    virtual ~Derived() { std::cout << "Derived::~Derived()" << std::endl; }

private:
    std::shared_ptr<test> t;
};
int main()
{
    try {
        Derived d;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    /*
     * Base::Base()
     * test::test()
     * test::~test()
     * Base::~Base()
     * std::exception
     */

    return 0;
}

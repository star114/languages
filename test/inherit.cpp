#include <iostream>

class Base
{
public:
    Base(){std::cout << "Base()" << std::endl;}
    virtual ~Base() { std::cout << "~Base()" << std::endl; }
    virtual void Func() { std::cout << "Base::Func()" << std::endl; }
};

class Derived : public Base
{
public:
    Derived() : Base() {std::cout << "Derived()" << std::endl;}
    ~Derived() override final { std::cout << "~Derived()" << std::endl;}
    void Func() override final { std::cout << "Derived::Func()" << std::endl; }
};

int main()
{
    Base* b = new Base();
    Derived* d = new Derived();

    ((Base*)d)->Func();
    (*(Base*)d).Func();

    delete b;
    delete d;
    return 0;
}

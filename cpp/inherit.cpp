#include <iostream>

class Base {
public:
    Base()
    {
        std::cout << "Base()" << std::endl;
    }
    virtual ~Base()
    {
        std::cout << "~Base()" << std::endl;
    }
    virtual void Func()
    {
        std::cout << "Base::Func()" << std::endl;
    }
};

class Derived : public Base {
public:
    Derived()
        : Base()
    {
        std::cout << "Derived()" << std::endl;
    }
    virtual ~Derived()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    void Func() override final
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

class Derived2 : public Base {
public:
    explicit Derived2(int input)
        : Base()
        , data(input)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    virtual ~Derived2()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    void Func() override final
    {
        std::cout << __PRETTY_FUNCTION__ << " data: " << data << std::endl;
    }

private:
    int data {0};
};

int main()
{
    auto b = std::make_unique<Base>();
    auto d = std::make_unique<Derived>();
    auto d2 = std::make_unique<Derived2>(10);

    // Base::Func()
    b->Func();
    // Base::Func()
    (*b).Func();

    // Derived::Func()
    (dynamic_cast<Derived*>(b.get()))->Func();
    // segmentation fault
    // (dynamic_cast<Derived2*>(b.get()))->Func();

    // Derived::Func()
    d->Func();
    // Derived::Func()
    (*d).Func();
    // Derived::Func()
    (dynamic_cast<Base*>(d.get()))->Func();
    // Derived::Func()
    (*(dynamic_cast<Base*>(d.get()))).Func();

    // Derived2::Func()
    d2->Func();
    // Derived2::Func()
    (*d2).Func();
    // Derived2::Func()
    (dynamic_cast<Base*>(d2.get()))->Func();
    // Derived2::Func()
    (*(dynamic_cast<Base*>(d2.get()))).Func();

    return 0;
}

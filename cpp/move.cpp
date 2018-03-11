#include <iostream>
#include <typeinfo>

static int test = 0;
class A {
public:
    A()
        : _a(0)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    explicit A(int a)
        : _a(a)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    A(const A& rhs)
        : _a(rhs._a)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    A(A&& rhs)
        : _a(std::move(rhs._a))
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    ~A()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        test++;
    }

    int get() const { return _a; }

private:
    int _a;
};

class B {
public:
    B()
        : _b(0)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    explicit B(int b)
        : _b(b)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    B(const B& rhs)
        : _b(rhs._b)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    B(B&& rhs)
        : _b(std::move(rhs._b))
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    ~B() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    void print() { std::cout << _b.get() << std::endl; }

private:
    A _b;
};

B print(B&& b)
{
    std::cout << typeid(b).name() << std::endl;
    b.print();
    B b2(2);
    return b2;
}

int main()
{
    {
        B b(B(1));
        // 1
        b.print();

        B b2(std::move(B(10)));
        // 10
        b2.print();

        // 1
        auto b3 = print(std::move(b));
        // 2
        b3.print();
        // std::move is just type casting function, don't move anything inside.
        // so we can call b.print() since print function doesn't move b.
        // 1
        b.print();

        // 100
        auto b4 = print(std::move(B(100)));
        // 2
        b4.print();

        // print function should get && (rvalue) reference only.
        //auto b5 = print(b);
        //b5.print();

    }

    std::cout << "A::~A() is called in " << test << " times." << std::endl;
    return 0;
}

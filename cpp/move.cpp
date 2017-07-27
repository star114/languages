#include <iostream>

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
    b.print();
    B b2(2);
    return b2;
}

int main()
{
    {
        B b(B(1));
        //B b(std::move(B(1)));

        //print(std::move(b));
        //b.print();
    }
    std::cout << test << std::endl;
    return 0;
}

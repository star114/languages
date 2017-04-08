#include <iostream>

class A
{
public:
    A() : _a(0) { std::cout << "A::A()" << std::endl; }
    explicit A(int a) : _a(a) { std::cout << "A::A(int)" << std::endl; }
    A(const A& rhs) : _a(rhs._a) { std::cout << "A::Copy constructor" << std::endl; }
    A(A&& rhs) : _a(std::move(rhs._a)) { std::cout << "A::Move constructor" << std::endl; }

    int get() const { return _a; }
private:
    int _a;
};

class B
{
public:
    B() : _b(0) { std::cout << "B::B()" << std::endl; }
    explicit B(int b) : _b(b) { std::cout << "B::B(int)" << std::endl; }
    B(const B& rhs) : _b(rhs._b) { std::cout << "B::Copy constructor" << std::endl; }
    B(B&& rhs) : _b(std::move(rhs._b)) { std::cout << "B::Move constructor" << std::endl; }

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
    B b(1);
    //B b(std::move(B(1)));

    print(std::move(b));
    b.print();
    return 0;
}

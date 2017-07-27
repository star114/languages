#include <stdio.h>
#define TEST_(a, b) ";a;b;"
#include <iostream>

enum Type {
    Ta,
    Tb,
    Tc
};

class test {
private:
    int a;
    double b;
    char c;
    Type type;

public:
    explicit test(Type t)
        : type(t)
    {
    }
    void setA(int aa) { a = aa; }
    void setB(double bb) { b = bb; }
    void setC(char cc) { c = cc; }
    template <typename T>
    const T& getValue()
    {
        if (type == Type::Ta)
            return a;
        else if (type == Type::Tb)
            return b;
        else if (type == Type::Tc)
            return c;
        else
            throw;
    }
};

int main()
{
    printf("%s\n", TEST_(SEL, IBM));
    test t1 = test(Type::Ta);
    t1.setA(1);
    test t2 = test(Type::Tb);
    t2.setB(2);
    test t3 = test(Type::Tc);
    t3.setC('a');

    std::cout << t1.getValue() << " " << t2.getValue() << " " << t3.getValue() << std::endl;
    return 0;
}

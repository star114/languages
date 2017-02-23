#include <iostream>

struct A
{
   bool a : 1;
   int b : 1;
   bool c : 1;
};

struct B
{
    bool a;
    int b;
    bool c;
};

int main()
{
    A st;
    B bz;
    std::cout << "sizeof(A)=" << sizeof(A) << std::endl;
    std::cout << "sizeof(int)=" << sizeof(int) << std::endl;
    std::cout << "sizeof(bool)=" << sizeof(bool) << std::endl;
    std::cout << "sizeof(B)=" << sizeof(B) << std::endl;
    std::cout << "sizeof(B.a)=" << sizeof(bz.a) << std::endl;
    std::cout << "sizeof(B.b)=" << sizeof(bz.b) << std::endl;
    std::cout << "sizeof(B.c)=" << sizeof(bz.c) << std::endl;
    st.b = 65536;
    std::cout << "after set 65536 in bit field : " << st.b << std::endl;
    return 0;
}

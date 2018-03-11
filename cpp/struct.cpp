#include <iostream>

struct A {
    bool a : 1;
    int b : 1;
    bool c : 1;
};

struct B {
    bool a;
    int b;
    bool c;
};

struct C {
    bool a;
    bool b;
    int c;
};

int main()
{
    // 4 byte
    std::cout << "sizeof(int)=" << sizeof(int) << std::endl;
    // 1 byte
    std::cout << "sizeof(bool)=" << sizeof(bool) << std::endl;

    // 4 byte
    std::cout << "sizeof(A)=" << sizeof(A) << std::endl;

    A st;
    st.b = 65536;
    // 0
    std::cout << "after set 65536 in bit field : " << st.b << std::endl;
    st.b = 1;
    // -1
    std::cout << "after set 1 in bit field : " << st.b << std::endl;

    struct Test {
        int test : 1; // -1..0
        bool test2 : 1; // 0, 1
        int test3 : 3; // -4..3
    };
    Test tt;
    tt.test = 1;
    tt.test2 = 1;
    tt.test3 = 3;
    // -1, 1, 3
    std::cout << tt.test << ", " << tt.test2 << ", " << tt.test3 << std::endl;

    B bz;
    // 12 byte
    std::cout << "sizeof(B)=" << sizeof(B) << std::endl;
    // 1 byte
    std::cout << "sizeof(B.a)=" << sizeof(bz.a) << std::endl;
    // 4 byte
    std::cout << "sizeof(B.b)=" << sizeof(bz.b) << std::endl;
    // 1 byte
    std::cout << "sizeof(B.c)=" << sizeof(bz.c) << std::endl;

    bz.b = 65536;
    // 65536
    std::cout << "after set 65536 in int field : " << bz.b << std::endl;

    // 8 byte
    std::cout << "sizeof(C)=" << sizeof(C) << std::endl;

    return 0;
}

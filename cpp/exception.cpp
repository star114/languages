#include <iostream>

using namespace std;
class data {
public:
    data() { cout << "data ()" << endl; }
    ~data() { cout << "~data ()" << endl; }
};

class test {
public:
    test()
        : d(new data())
    {
        cout << "test()" << endl;
        throw "??";
    }
    ~test()
    {
        delete d;
        cout << "~test()" << endl;
    }
    data* d;
};

int main()
{
    try {
        cout << "start program" << endl;
        test a;
        cout << "succeed." << endl;
    } catch (...) {
        cout << "catched" << endl;
    }
    return 0;
}

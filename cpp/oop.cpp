#include <iostream>

using namespace std;
class Base
{
public:
    Base() { cout << "Base()" << endl; }
    virtual ~Base() { cout << "~Base()" << endl; }
    virtual void InnerFunc() { cout << "Base::InnerFunc()" << endl; }
    virtual void outerFunc()
    {
        cout << "Base::outerFunc()" << endl;
        InnerFunc();
    }
};

class Derived : public Base
{
public:
    Derived() : Base() { cout << "Derived()" << endl; }
    virtual ~Derived() { cout << "~Derived()" << endl; }
    void InnerFunc() { cout << "Derived::InnerFunc()" << endl; }
    void outerFunc() { Base::outerFunc(); }
};

int main()
{
    cout << "started.." << endl;

    Base* a = new Derived();
    a->outerFunc();
    delete a;
    cout << "ended.." << endl;
    return 0;
}

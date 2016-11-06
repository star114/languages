#include <iostream>

class Poly
{
public:
    Poly () {}
    int getValue() const
    {
        if (bCached)
        {
            std::cout << "cached value : " << cachedVal << std::endl;
        }
        else
        {
            std::cout << "will be cached... : " << cachedVal << std::endl;
            cachedVal = 1;
            bCached = true;
        }
        return cachedVal;
    }
private:
    // should be declared with mutable if you assign value in const member method
    mutable int cachedVal{0};
    mutable bool bCached{false};
    //int cachedVal{0};
    //bool bCached{false};
};

int main()
{
    Poly a;
    a.getValue();

    Poly b;
    b.getValue();
    a.getValue();
    b.getValue();
    return 0;
}

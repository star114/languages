#include <iostream>
#include <exception>

class base
{
public:
    base() : val (0) { std::cout << "base()" << std::endl; }
    void test() { std::cout << "base::test()" << val << std::endl; }
private:
    int val;
};
int main()
{
    std::cout << "hi" << std::endl;
    try
    {
        base* b = nullptr;
        //divide by zero
        std::cout << 1.0 / 0.0 << std::endl;
    //    b->test();
        std::cout << "!" << std::endl;
        throw 1;
    }
    catch (std::exception& e)
    {
        std::cout << " std:: exception " << std::endl;
    }
    catch (...)
    {
        std::cout << "catched!" << std::endl;
    }
    return 0;
}

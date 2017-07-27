// cannot be overloaded in this case - error at compilation time

#include <iostream>
#include <string>
#include <type_traits>

struct T {
    enum { int_t,
        float_t } m_type;
    template <typename Integer,
        typename = std::enable_if_t<std::is_integral<Integer>::value>>
    T(Integer)
        : m_type(int_t)
    {
    }

    template <typename Floating,
        typename = std::enable_if_t<std::is_floating_point<Floating>::value>>
    T(Floating)
        : m_type(float_t)
    {
    } // error: cannot overload
};

int main()
{
    auto a = T(0);
    auto b = T(0.0);
    std::cout << a.m_type << std::endl;
    std::cout << b.m_type << std::endl;
    return 0;
}

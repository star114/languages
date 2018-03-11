/*
 * 1) 디폴트 템플릿 파라미터는 템플릿 펑션 시그니처에 안들어감(그래서 typename = std::enable_if_t(condition, type))의 condition만 다른 두 함수를 만들 수 없음
 * 2) enable_if의 type이 int char등 넌 타입 템플릿에 올 수 있는 타입이여야 함.(더블 안됨) 그래야 typename int = 0형태인 넌 타입 템플릿 파라미터 형식으로 추론됨
 * 올수 이는 녀석은 nullptr, integral lvalue reference, pointer, enum 이라고 함
 */

#include <iostream>
#include <string>
#include <type_traits>

struct T {
    enum { int_t,
        float_t } m_type;
    template <typename Integer,
//        typename = std::enable_if_t<std::is_integral<Integer>::value>>
        typename std::enable_if_t<std::is_integral<Integer>::value, int> = 0>
    explicit T(Integer)
        : m_type(int_t)
    {
    }

    template <typename Floating,
//        typename = std::enable_if_t<std::is_floating_point<Floating>::value>>
// error: cannot overload
        typename std::enable_if_t<std::is_floating_point<Floating>::value, int> = 0>
    explicit T(Floating)
        : m_type(float_t)
    {
    }
};

int main()
{
    auto a = T(0);
    auto b = T(0.0);
    std::cout << a.m_type << std::endl;
    std::cout << b.m_type << std::endl;
    return 0;
}

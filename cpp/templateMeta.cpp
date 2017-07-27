#include <iostream>

class Test {
public:
    template <typename T, typename = typename std::enable_if<!std::is_base_of<Test>::value>>
        ::value > Test(T&& rhs)
        : name(std::forward<T>(rhs))
    {
    }

private:
    std::string name;
};

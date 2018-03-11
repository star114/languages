#include <iostream>
#include <typeinfo>
#include <string>

class Base {
public:
    Base() = default;
    virtual ~Base() = default;

    virtual void print(std::ostream& os)
    {
        os << "Base" << std::endl;
    }
    std::ostream& operator <<(std::ostream& os)
    {
        print(os);
        return os;
    }
};

class Derived : public Base {
public:
    Derived() = default;
    virtual ~Derived() = default;

    void print(std::ostream& os) override
    {
        os << "Derived" << std::endl;
    }
    std::ostream& operator <<(std::ostream& os)
    {
        print(os);
        return os;
    }
};

class Test {
public:
    Test() = default;
    ~Test() = default;
    void print(std::ostream& os)
    {
        std::cout << "Test" << std::endl;
    }
    std::ostream& operator <<(std::ostream& os)
    {
        print(os);
        return os;
    }
};

template <typename T>
void print_typeof (T const& x)
{
    std::cout << typeid(x).name() << std::endl;
}

template <typename T, typename std::enable_if_t<std::is_base_of<Base, typename std::decay_t<T>>::value, int> = 0>
void func(T&& arg)
{
    std::cout << std::forward<T>(arg) << std::endl;
}

template <typename T, typename std::enable_if_t<!std::is_base_of<Base, typename std::decay_t<T>>::value, int> = 0>
void func(T&& arg)
{
    std::cout << "NO!! " << std::forward<T>(arg) << std::endl;
}

template<typename... T>
void funcs(T... args)
{
    using expand = int[];
    expand{0, (func(args), 0)... };
}

template<typename... T>
void univ_funcs(T&&... args)
{
    using expand = int[];
    expand{0, (func(std::forward<T>(args)), 0)... };
}

void print() {}
template <typename A, typename... Args>
void print(A a, Args... args)
{
    std::cout << a;
    print(args...);
}

void wrapperFunc() {}

template <typename A, typename... Args>
void wrapperFunc(A a, Args... args)
{
    func(a);
    wrapperFunc(args...);
}

template <typename T>
class TD;

int main()
{
    Derived d1;
    Base& b1 = d1;
    std::cout << "reference to non-polymorphic base: " << typeid(b1).name() << '\n';
    //funcs(0, 1, 2);
    //univ_funcs(3, 4, 5);

    //print(1, "hi", 0.0);

    //wrapperFunc(1, "hi", 0.0, 3);

    auto test1 = std::make_unique<Test>();
    auto test2 = std::make_unique<Base>();
    auto test3 = std::make_unique<Derived>();
    //wrapperFunc(test1.get(), test2.get(), test3.get());
    //func<Base*>(test2.get());
    //print_typeof(test1.get());

    func(test1.get());
    auto testP = test1.get();
    std::cout << std::is_base_of<Base, typename std::decay<Test *>::type>::value << std::endl;
    std::cout << std::is_base_of<Base, typename std::remove_pointer<Base *>::type>::value << std::endl;
    std::cout << std::is_base_of<Base, typename std::remove_pointer<Derived *>::type>::value << std::endl;
    std::cout << std::is_base_of<Base, typename std::remove_pointer<typename std::remove_reference<Derived *&>::type>::type>::value << std::endl;
    return 0;
}

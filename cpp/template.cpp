#include <iostream>
#include <typeinfo>

template <typename T>
void foo(T& x)
{
}

template<typename T> class my_array
{
public:
    void print() { std::cout << typeid(T).name() << std::endl; }
};

template<typename T>
void print_typeof(T const& x)
{
    std::cout << typeid(x).name() << std::endl;
}

template<typename T>
void print_typeinfo()
{
    std::cout << typeid(T).name() << std::endl;
}

template<typename... T> class my_variadic_array
{
public:
    void print()
    {
        using expand = int[];
        expand{0, (print_typeinfo<T>(), 0)...  };
    }
};
// two type template parameters and one template template parameter:
template<typename K, typename V, template<typename> class C = my_array>
class Map
{
public:
    void print() { key.print(); value.print(); }
private:
    C<K> key;
    C<V> value;
};

template<typename K, typename V, template<typename... Args> class C = my_variadic_array>
class vMap
{
public:
    void print() { key.print(); value.print(); }
private:
    C<K> key;
    C<V> value;
};

int main()
{
    int x = 42;
    foo(x);
    int const cx = x;
    foo(cx);
    int const& rx = x;
    foo(rx);
    Map<int, int> a;
    a.print();
    vMap<int, int> b;
    b.print();
}

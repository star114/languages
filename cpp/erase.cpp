#include <iostream>
#include <vector>

template <typename T>
void print(std::vector<T>& v)
{
    std::cout << "vector : size - " << v.size() << std::endl;
    for (auto& entry : v) {
        std::cout << entry << std::endl;
    }
}

int main()
{
    std::vector<int> a{ 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    // 0, 1, 2, 3, 4, 5, 6, 7, 8
    print<int>(a);
    auto itr = a.begin();
    auto end = a.end();
    for (; itr != end;) {
        std::cout << "before erase - " << (*itr) << " end - " << *end << std::endl;
        std::cout << "itr at position " << (itr - a.begin()) << std::endl;
        std::cout << "end at position " << (end - a.begin()) << std::endl;

        if ((*itr) % 2 == 0) {
            itr = a.erase(itr);
            // we should update the end of iterator
            // if we don't update end, it got segmentation fault.
            // saved end iterator is not valid after erase something in the container1
            // Please be careful to use erase!
            end = a.end();
        }
        else
            ++itr;

        std::cout << "after erase - " << (*itr) << " end - " << *end << std::endl;
        std::cout << "itr at position " << (itr - a.begin()) << std::endl;
        std::cout << "end at position " << (end - a.begin()) << std::endl;
    }
    // 1, 3, 5, 7
    print<int>(a);
    return 0;
}

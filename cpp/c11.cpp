#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vi;
    vi.emplace_back(1);
    vi.emplace_back(2);
    vi.emplace_back(3);

    for (auto entry : vi)
    {
        std::cout << entry << std::endl;
    }

    return 0;
}

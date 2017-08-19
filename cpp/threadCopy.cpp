#include <iostream>
#include <thread>
#include <vector>

void hello()
{
    std::cout << "hello world" << std::endl;
}

int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i)
        threads.push_back(std::thread(hello));
    for (auto& th : threads)
        th.join();
}

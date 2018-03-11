#include <iostream>
#include <mutex>
#include <stdlib.h>

std::mutex m;
unsigned int counter = 0;

unsigned int increment()
{
    std::lock_guard<std::mutex> lg(m);
    return ++counter;
}

unsigned int query()
{
    std::lock_guard<std::mutex> lg(m);
    return counter;
}

int main(int argc, const char* argv[])
{
    std::cout << query() << std::endl;
    increment();
    std::cout << query() << std::endl;
    return 0;
}

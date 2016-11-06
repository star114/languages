#include <ctime>
#include <iostream>

int main() {
    time_t t = std::time(0);   // get time now
    struct tm * now = std::localtime( & t );
    std::cout << (now->tm_year + 1900) << '-';
    std::cout.width(2);
    std::cout.fill('0');
  	std::cout << (now->tm_mon + 1) << '-';
  	std::cout.width(2);
    std::cout.fill('0');

    std::cout << now->tm_mday << std::endl;
}
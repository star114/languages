#include <functional>
#include <iostream>
#include <memory>
#include <stdlib.h>
#include <string>
#include <thread>

class Greeting {
    std::string message;

public:
    explicit Greeting(std::string const& message_)
        : message(message_)
    {
    }
    void operator()() const
    {
        std::cout << message << std::endl;
    }
};

class SayHello {
public:
    void greeting(std::string const& message)
    {
        std::cout << message << std::endl;
    }
};

class PrintThis {
public:
    void operator()() const
    {
        std::cout << "this=" << this << std::endl;
    }
};

void greeting(std::string const& message)
{
    std::cout << message << std::endl;
}

void my_thread_callback()
{
    std::cout << "hello!" << std::endl;
}

void increment(int& i)
{
    ++i;
}

int main(int argc, const char* argv[])
{
    std::thread t(my_thread_callback);
    // hello!
    t.join();
    std::thread t2(Greeting("goodbye"));
    // goodbye
    t2.join();
    std::thread t3(std::bind(greeting, "hi!")); // std::bind : support on c++11
    // hi!
    t3.join();
    std::thread t4(greeting, "good!");
    // good!
    t4.join();
    SayHello x;
    std::thread t5(&SayHello::greeting, &x, "Good to see you!");
    // Good to see you!
    t5.join();
    auto p = std::make_shared<SayHello>();
    std::thread t6(&SayHello::greeting, p, "Greetings!!");
    // Grettings!!
    t6.join();
    PrintThis y;
    y();
    // referenece of y
    std::thread t7(std::ref(y)); // same as y();
    t7.join();
    // copied from y
    std::thread t8(y);
    t8.join();
    std::thread t9(std::ref(greeting), "ref greeting!");
    // ref greeting!
    t9.join();
    int k = 42;
    std::thread t10(increment, std::ref(k));
    t10.join();
    // k=43
    std::cout << "k=" << k << std::endl;
    return 0;
}

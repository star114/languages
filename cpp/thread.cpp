/*
 * =====================================================================================
 *
 *       Filename:  thread.cpp
 *
 *    Description:  thread test program.
 *
 *        Version:  1.0
 *        Created:  08/11/15 16:38:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Heesik Shin (star114), star114.shin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <thread>
#include <iostream>
#include <string>
#include <functional>
#include <memory>

class Greeting
{
    std::string message;
  public:
    explicit Greeting(std::string const& message_) :
      message(message_)
    {}
    void operator()() const
    {
      std::cout << message << std::endl;
    }
};

class SayHello
{
  public:
    void greeting(std::string const& message)
    {
      std::cout << message << std::endl;
    }
};

class PrintThis
{
  public:
    void operator()() const
    {
      std::cout << "this=" <<this << std::endl;
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

int main(int argc, const char *argv[])
{
  std::thread t(my_thread_callback);
  t.join();
  std::thread t2(Greeting("goodbye"));
  t2.join();
  std::thread t3(std::bind(greeting, "hi!")); // std::bind : support on c++11
  t3.join();
  std::thread t4(greeting, "good!");
  t4.join();
  SayHello x;
  std::thread t5(&SayHello::greeting, &x, "Good to see you!");
  t5.join();
  std::shared_ptr<SayHello> p(new SayHello);
  std::thread t6(&SayHello::greeting, p, "Greetings!!");
  t6.join();
  PrintThis y;
  y();
  std::thread t7(std::ref(y));
  t7.join();
  std::thread t8(y);
  t8.join();
  std::thread t9(std::ref(greeting), "ref greeting!");
  t9.join();
  int k = 42;
  std::thread t10(increment, std::ref(k));
  t10.join();
  std::cout << "k=" <<k << std::endl;
  return 0;
}

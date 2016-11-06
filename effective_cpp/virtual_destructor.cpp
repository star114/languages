/*
 * =====================================================================================
 *
 *       Filename:  virtual_destructor.cpp
 *
 *    Description:  test virtual destructor
 *
 *        Version:  1.0
 *        Created:  08/19/15 09:21:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Heesik Shin (star114), star114.shin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>

class Base 
{
public:
  Base()
  {
    std::cout << "Base ()" << std::endl;
  }
  virtual ~Base()
  {
    std::cout << "~Base ()" << std::endl;
  }
};

class Derived : public Base
{
public:
  Derived()
  {
    std::cout << "Derived ()" << std::endl;
  }
  ~Derived()
  {
    std::cout << "~Derived ()" << std::endl;
  }
};

int main(int argc, const char *argv[])
{
  Derived* pd = new Derived();
  Base* p = pd;
  if (NULL != p)
    delete p;
  return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  virtual.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/02/15 22:55:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Heesik Shin (star114), star114.shin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>

class A
{
  public:
    A() { std::cout << "A ()" << std::endl; }
    virtual ~A() { std::cout << "~A ()" << std::endl; } // must declare virtual destructor.
};

class B : public A
{
  public:
    B() : A() { std::cout << "B ()" << std::endl; }
    virtual ~B() { std::cout << "~B ()" << std::endl; }
};

class C : public A
{
  public:
    C() : A() { std::cout << "C ()" << std::endl; }
    virtual ~C() { std::cout << "~C ()" << std::endl; }
};

class D : public B, public C
{
  public:
    D() : B(), C() { std::cout << "D ()" << std::endl; }
    ~D() { std::cout << "~D ()" << std::endl; }
};

class B_virtual : virtual public A
{
  public:
    B_virtual() : A() { std::cout << "B_virtual ()" << std::endl; }
    virtual ~B_virtual() { std::cout << "~B_virtual ()" << std::endl; }
};

class C_virtual : virtual public A
{
  public:
    C_virtual() : A() { std::cout << "C_virtual ()" << std::endl; }
    virtual ~C_virtual() { std::cout << "~C_virtual ()" << std::endl; }
};

class D_virtual :public B_virtual, public C_virtual
{
  public:
    D_virtual() : B_virtual(), C_virtual() { std::cout << "D_virtual ()" << std::endl;}
    ~D_virtual() { std::cout << "~D_virtual ()" << std::endl; }
};

int main(int argc, const char *argv[])
{
  D d;
  std::cout << "=======" << std::endl;
  D_virtual d_virtual;
  std::cout << "=======" << std::endl;
  //A* a = new D(); // ambiguous. g++
  A* a = new B();
  std::cout << "=======" << std::endl;
  A* a2 = new D_virtual();
  std::cout << "======= destructor =======" << std::endl;
  delete a;
  std::cout << "=======" << std::endl;
  delete a2; // D_virtual -> C_virtual -> B_virtual -> A
  std::cout << "=======" << std::endl;
  return 0;
}

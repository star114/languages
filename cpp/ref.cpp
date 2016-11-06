/*
 * =====================================================================================
 *
 *       Filename:  ref.cpp
 *
 *    Description:  std::ref, std::bind example
 *
 *        Version:  1.0
 *        Created:  08/12/15 21:57:34
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
#include <functional>

void increment( int& x)
{
  ++x;
}

int main(int argc, const char *argv[])
{
  int i =0 ;

  // Here, we bind increment to (a copy of) i...
  std::function<void()> bound_f = std::bind(increment, i); // bind return the resulting function object
  bound_f();

  // i is still 0
  std::cout << i << std::endl;

  // Now, we bind increment to std::ref(i)!
  std::function<void()> bound_f2 = std::bind(increment, std::ref(i));
  bound_f2();
  //increment(&i);
  //std::bind(increment, &i)();

  // i has now been incremented.
  std::cout << i << std::endl;
  
  return 0;
}


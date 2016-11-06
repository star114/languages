/*
 * =====================================================================================
 *
 *       Filename:  template.cpp
 *
 *    Description:  metaprogramming of template
 *
 *        Version:  1.0
 *        Created:  09/02/15 14:58:10
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

template <unsigned int N>
struct factorial{
  enum {
    value = N * factorial<N-1>::value
  };
};

template <>
struct factorial<0>{
  enum {
    value = 1
  };
};

int main(int argc, const char *argv[])
{
  std::cout << factorial<5>::value << std::endl;
  return 0;
}

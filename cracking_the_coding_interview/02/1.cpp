/*
 * =====================================================================================
 *
 *       Filename:  1.cpp
 *
 *    Description:  delete same character
 *
 *        Version:  1.0
 *        Created:  09/02/15 15:23:55
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
#include "linkedlist.hpp"

int main(int argc, const char *argv[])
{
  dev_base::linkedlist<char> test;
  test.push_back('a');
  test.push_back('b');
  test.push_back('c');
  test.push_back('b');
  test.push_back('a');
  test.print();
  test.unique();
  test.print();
  return 0;
}


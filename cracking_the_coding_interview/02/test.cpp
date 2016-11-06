/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  test module
 *
 *        Version:  1.0
 *        Created:  08/28/15 16:12:10
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
  std::cout << "start testing ..." << std::endl;
  dev_base::linkedlist<int> lst;
  std::cout << "declaration test success" << std::endl;
  lst.push_back(1);
  lst.print();
  lst.push_back(2);
  lst.push_back(3);
  lst.print();
  std::cout << "push_back test success" << std::endl;
  std::cout << lst.pop_back() << std::endl;
  lst.print();
  std::cout << "stop testing ..." << std::endl;
  return 0;
}


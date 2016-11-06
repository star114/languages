/*
 * =====================================================================================
 *
 *       Filename:  mutex.cpp
 *
 *    Description:  mutex sample
 *
 *        Version:  1.0
 *        Created:  08/12/15 22:22:30
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
#include <mutex>

std::mutex m;
unsigned int counter  = 0;

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

int main(int argc, const char *argv[])
{
  std::cout << query() << std::endl;
  increment();
  std::cout << query() << std::endl;
  return 0;
}

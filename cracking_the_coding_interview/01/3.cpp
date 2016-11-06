/*
 * =====================================================================================
 *
 *       Filename:  3.cpp
 *
 *    Description:  problem 1.3
 *                  문자열 두 개를 입력으로 받아 그중 하나가 다른 하나의 순열인지 판별하는 메서드를
 *                  작성하라.
 *
 *        Version:  1.0
 *        Created:  08/21/15 17:46:36
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
#include <string>
#include <algorithm>

bool isPermutation(std::string str1, std::string str2)
{
  if (str1.length() != str2.length()) return false;
  
  std::sort(str1.begin(), str1.end());
  std::sort(str2.begin(), str2.end());
 
  // debugging string
  // std::cout << "str1 : " << str1 << std::endl;
  // std::cout << "str2 : " << str2 << std::endl;
  
  return (0 == str1.compare(str2));
}

// Tests
int main(int argc, const char *argv[])
{
  std::string s1("hello");
  std::string s2("olleh");
  std::cout << isPermutation(s1, s2) << std::endl;
  return 0;
}

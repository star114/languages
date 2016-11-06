/*
 * =====================================================================================
 *
 *       Filename:  8.cpp
 *
 *    Description:  problem 1.8
 *                  한 단어가 다른 단어에 포함된 문자열인지 판별하는 isSubstring이라는 메서드가
 *                  있다고 하자. s1과 s2의 두 문자열이 주어졌을 때, s2가 s1을 회전시킨 결과인지
 *                  판별하는 코드를 isSubstring을 한번만 호출하도록 하여 작성하라. (가령
 *                  'waterbottle'은 'erbottlewat' 을 회전시켜 얻을 수 있는 문자열이다.)
 *
 *        Version:  1.0
 *        Created:  08/21/15 18:13:18
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

bool isRotatedString(const std::string& str1, const std::string& str2)
{
  std::string str(str1);
  str.append(str);
  //debugging string
  //std::cout << str << " " << str.find(str2) << std::endl;
  return str.find(str2) != std::string::npos; // it is the same as isSubstring Function.
}

// Tests
int main(int argc, const char *argv[])
{
  std::string str1("My name is Heesik");
  std::string str2("HeesikMy name is ");
  std::cout << isRotatedString(str1, str2) << std::endl;
  return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  5.cpp
 *
 *    Description:  problem 1.5
 *                  같은 문자가 연속으로 반복될 경우, 그 횟수를 사용해 문자열을 압축하는 메서드를
 *                  구현하라. 가령 압축해야 할 문자열이 aabccccccccaaa 라면 a2b1c8a3과 같이
 *                  압축되어야 한다. 압축 결과로 만들어지는 문자열이 원래 문자열보다 짧아지지 않는
 *                  경우, 이 메서드는 원래 문자열을 그대로 반환해야 한다.
 *
 *        Version:  1.0
 *        Created:  08/21/15 18:03:53
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
#include <sstream>

int compute_compress_string_length(const std::string str)
{
  int len = str.length();
  int newlen = len;
  if (len > 0)
  {
    int count = 1;
    char cCurrent = str[0];
    for(int i = 1 ; i < len ; i++)
    {
      if (cCurrent == str[i])
        count ++;
      else{
        newlen += (1 + count / 10 - count);
        count = 1;
        cCurrent = str[i];
      }
    }
  }
  return newlen;
}

std::string compress_string(std::string str)
{
  int len = str.length();
  int newlen = compute_compress_string_length(str);
  if (len <= newlen) return str;
  
  std::stringstream ss;
  int count = 1;
  char c = str[0];
  for (int i = 1; i < len; i++)
  {
    if (c == str[i])
      count ++;
    else{
      ss << c << count;
      c = str[i];
      count = 1;
    }
  }
  ss << c << count;
  return ss.str();
}

// Tests
int main(int argc, const char *argv[])
{
  std::string str("aaabbcccd");
  std::cout << str << std::endl;
  std::cout << compress_string(str) << std::endl;

  std::string str2("abcde");
  std::cout << str2 << std::endl;
  std::cout << compress_string(str2) << std::endl;
  return 0;
}


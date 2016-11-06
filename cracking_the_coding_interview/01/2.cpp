/*
 * =====================================================================================
 *
 *       Filename:  2.cpp
 *
 *    Description:  problem 1.2
 *                  널 문자로 끝나는 문자열을 뒤집는 reverse(char* str) 함수를 C나 C++ 로
 *                  구현하여라.
 *
 *        Version:  1.0
 *        Created:  08/21/15 17:38:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Heesik Shin (star114), star114.shin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <functional>
#include <iostream>

void reverse(char* str)
{
  int nLength = strlen(str);
  for (int i= 0 ; i < nLength /2 ; i++)
    std::swap(str[i], str[nLength - 1 - i]);
}


int main(int argc, const char *argv[])
{
  // Test code.
  char ch[256] = {0, };
  strcpy(ch, "Life is...");
  std::cout << ch << std::endl;
  reverse(ch);
  std::cout << ch << std::endl;
  return 0;
}

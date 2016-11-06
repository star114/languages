/*
 * =====================================================================================
 *
 *       Filename:  4.cpp
 *
 *    Description:  problem 1.4
 *                  주어진 문자열 내의 모든 공백을 '%20'으로 바꾸는 메서드를 작성하라. 문자열 끝에
 *                  추가로 필요한 문자들을 더할 수 있는 공간이 있다고 가정하라. 그리고 공백을
 *                  포함하는 문자열의 길이도 함께 주어진다고 가정하라.
 *                  - 예시
 *                  Input : "Mr John Smith ", 13
 *                  Output : "Mr%20John%20Smith"
 *
 *        Version:  1.0
 *        Created:  08/21/15 17:59:55
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

int compute_new_len(const char* str, int n)
{
  int newlen = n;
  for (int i = 0; i < n ; i++)
  {
    if (str[i] == ' ')
    {
      newlen += 2;
    }
  }
  return newlen;
}

void replace_space(char* str, int n)
{
  int newlen = compute_new_len(str, n) - 1;
  for (int i = n - 1; i >= 0 ; i--)
  {
    if (str[i] == ' ')
    {
      str[newlen--] = '0';
      str[newlen--] = '2';
      str[newlen--] = '%';
    }
    else 
      str[newlen--] = str[i];
  }
}

// Test
int main(int argc, const char *argv[])
{
  char* str = new char[256];
  memset(str, 0, sizeof(char) * 256);
  strcpy(str, "Mr Heesik Shin    "); 
  std::cout << "before replace : " << str << ":::" << std::endl;
  replace_space(str, 14);
  std::cout << "after replace : " << str << ":::" << std::endl;

  return 0;
}


/*
 * =====================================================================================
 *
 *       Filename:  1.cpp
 *
 *    Description:  problem 1.1
 *                  문자열에 포함된 문자들이 전부 유일한지를 검사하는 알고리즘을 구현하라.
 *                  다른 자료구조를 사용할 수 없는 상황이라면 어떻게 하겠는가?
 *
 *        Version:  1.0
 *        Created:  08/21/15 17:25:23
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
// assume that the program handle the ascii string.

// count of ascii code.
const int MAX_CHARACTER_COUNT = 256;
bool isUniqueCharactersString(const char* str)
{
  int nLength = strlen(str);
  if (nLength > 256) return false;

  bool abCharacter[MAX_CHARACTER_COUNT] = {false,};
  for(int i = 0 ; i < nLength; i++)
  {
    if (abCharacter[str[i]]) return false;
    else abCharacter[str[i]] = true;
  }
  return true;
}


// test code.
int main(int argc, const char *argv[])
{
  //success cases
  std::cout << isUniqueCharactersString("String") << std::endl;
  //false cases
  std::cout << isUniqueCharactersString("NoNo") << std::endl;
  
  return 0;
}




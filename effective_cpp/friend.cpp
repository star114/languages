/*
 * =====================================================================================
 *
 *       Filename:  friend.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/03/15 09:20:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Heesik Shin (star114), star114.shin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

class lstring
{
  public:
    lstring();
    ~lstring();
    lstring(const lstring& str);
    lstring(const wchar_t* wsz);
    friend bool operator==(const lstring& lhs, const lstring& rhs);
    // binary operator must declare as friend.
    // its definition is in global section.
    // if it is not defined as friend, it will occur compile error.
  private:
    wchar_t* m_buffer;
};

lstring::lstring()
  : m_buffer(NULL)
{
}
lstring::lstring(const lstring& str)
  : m_buffer(str.m_buffer)
{
  
}
lstring::lstring(const wchar_t* wsz)
  : m_buffer(const_cast<wchar_t*>(wsz))
{

}
lstring::~lstring()
{
}

bool operator==(const lstring& lhs, const lstring& rhs)
{
  return (0 == wcscmp(lhs.m_buffer, rhs.m_buffer));
}

int main(int argc, const char *argv[])
{
  lstring str(L"test");
  lstring str2(L"test2");
  lstring str3(L"test");
  printf("str != str2 (%d) str == str3(%d)\n", str == str2, str == str3);
  return 0;
}

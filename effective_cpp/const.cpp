/*
 * =====================================================================================
 *
 *       Filename:  const.cpp
 *
 *    Description:  const test
 *
 *        Version:  1.0
 *        Created:  07/31/15 21:07:50
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

class TextBlock {
public:
  explicit TextBlock(){}
  explicit TextBlock(std::string strText) : text(strText), lengthIsValid(false){pText = const_cast<char*>(strText.c_str());}
  explicit TextBlock(char* pchText) : pText(pchText), lengthIsValid(false){}
  virtual ~TextBlock(){}
  

  const char& operator[] (std::size_t position) const { std::cout << "called const" << std::endl; return text[position];}
 // char& operator[] (std::size_t position) 
 // { std::cout << "called normal" <<std::endl; 
 //   return text[position];//const_cast<char&>(static_cast<const TextBlock> (*this)[position]);
 // }

//  std::size_t length();
  std::size_t length() const;
private:
  char *pText;
  std::string text;

  mutable std::size_t textlength;
  mutable bool lengthIsValid;
};



//std::size_t TextBlock::length()
//{
//  if (!lengthIsValid){
//    textlength = std::strlen(pText);
//    lengthIsValid = true;
//  }
//  return textlength;
//}

std::size_t TextBlock::length() const
{
  if (!lengthIsValid) {
    textlength = std::strlen(pText);
    lengthIsValid = true;
  }
  return textlength;
}

int main(int argc, const char *argv[])
{
  TextBlock t1 (std::string("Hellow world"));
  const TextBlock t2 (std::string("Hello world"));
  std::cout << t1[0] << " " << t1.length() << std::endl;
  std::cout << t2[0] << " " << t2.length() << std::endl;
  return 0;
}

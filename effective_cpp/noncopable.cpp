/*
 * =====================================================================================
 *
 *       Filename:  noncopable.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/02/15 16:24:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Heesik Shin (star114), star114.shin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <boost/core/noncopyable.hpp>

class test: private boost::noncopyable
{

};

int main(int argc, const char *argv[])
{
  test t1;
  //test t2(t1);
  printf("hello BBO!!!\n");
  return 0;
}

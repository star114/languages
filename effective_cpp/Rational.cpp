/*
 * =====================================================================================
 *
 *       Filename:  Rational.cpp
 *
 *    Description:  Rational class
 *
 *        Version:  1.0
 *        Created:  08/11/15 14:33:54
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

class Rational{
  public:
    Rational(int numerator = 0, int denominator = 1); // Rational => int , for implicit cast
    ~Rational();
    void print()
    {
      std::cout << "Rational n: " << n << ", d: " << d << std::endl;
    }
    inline int numerator() const
    {
      return n;
    }
    inline int denominator() const
    {
      return d;
    }
    inline friend const Rational operator* (const Rational& lhs, const Rational& rhs);
  private:
    int n, d;
};

Rational::Rational(int numerator, int denominator)
: n(numerator), d(denominator)
{
}

Rational::~Rational()
{
}

const Rational operator *(const Rational& lhs, const Rational& rhs)
{
  Rational result(lhs.n * rhs.n , lhs.d * rhs.d);
  return result;
}


int main()
{
  Rational A(1,2);
  Rational B;
  Rational C = A*B;
  A.print();
  B.print();
  C.print();
  Rational D = A * 4; //implicit cast! (Rational(4))
  D.print();
  Rational E = 4 * 5;
  E.print();
  return 0;
}

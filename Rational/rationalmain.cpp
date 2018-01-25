// simple driver to test the Rational class
#include <iostream>
using namespace std;
#include "rational.h"

int main()
{
  Rational a(5,6), b(3,7), c, s;

  cout << "*** display a and b ***\n";
  a.print();
  b.print();
  cout << "*** display c ***\n";
  c.print();  // recall that c was instantiated with the default constructor

  // 'mathematically' add a and b
  cout << "*** compute s as the math sum of a and b, and display s ***\n";
  s = a.add(b);
  s.print();

  cout << "*** compute s as the difference of a and b, and display s ***\n";
  s = a.subtract(b);
  s.print();

  cout << "*** compute s as the math product of a and b, and display s ***\n";
  s = a.multiply(b);
  s.print();

  cout << "*** compute s as the math quotient of a and b, and display s ***\n";
  s = a.divide(b);
  s.print();

  return 0;
}


// Rational Implementation, Lab 7, Part 1
// Kathryn Stapleton, section 3, Oct 23

#include "rational.h"
#include<iostream>
using namespace std;

Rational::Rational()
{
   numer = 1;
   denom = 1;
}

Rational::Rational(int p, int q)
{
   numer= p;
   denom=q;
}

Rational::~Rational()
{ }

int Rational::getNumer()
{
   return numer;
}

int Rational::getDenom()
{
   return denom;
}

void Rational::setNumer(int p)
{
   numer= p;
}

void Rational::setDenom(int q)
{
   denom= q;
}

void Rational::print()
{
   cout << numer <<"/" << denom <<endl;
}
   
Rational Rational::add(Rational other)
{
   Rational s;
   s.setNumer(numer * other.getDenom()+ other.getNumer() * denom);
   s.setDenom(denom * other.getDenom());
   return s;
//   return (numer/denom) + (other.numer/other.denom);
}

Rational Rational::subtract(Rational other)
{
   Rational s;
   s.setNumer(numer * other.getDenom()- other.getNumer() * denom);
   s.setDenom(denom * other.getDenom());
   return s;

}

Rational Rational::multiply(Rational other)
{
   Rational s;
   s.setNumer(numer* other.getNumer());
   s.setDenom(denom* other.getDenom());
   return s;
} 

Rational Rational::divide(Rational other)
{
   Rational s;
   s.setNumer(numer* other.getDenom());
   s.setDenom(denom* other.getNumer());
   return s;

}

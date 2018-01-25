//Lab 7, in lab, create implementation for Circle class
// Kathryn Stapleton
#include "circle.h"
#include <cmath>

Circle::Circle()
{
   radius = 1;
}
Circle::Circle(float r)
{
   radius = r;
}
   
Circle::~Circle()
{ }

float Circle::getRadius()
{
   return radius;
}

void Circle::setRadius(float rad)
{
   radius = rad;
}

float Circle::circumference()
{
   return 2*3.14*radius;
}

float Circle::area()
{
   return 3.14*pow(radius, 2);
}

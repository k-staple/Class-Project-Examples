// Lab 2, Part 3
// Kathryn Stapleton, Section 1, Sept 10

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main () {
   cout << "The function is 15sin(x) + cos(x) +16 from x= 0 to 10" << endl;
   
   // set width of columns
   cout << fixed << setprecision(2);   

   // initialize
   double x= 0;
   double yprev= 0;
   double ynew= 0;
   string bar= "#";
   unsigned int countDigits= 0;
   double yMax = 0;
   double yMin= 0;
   double xOfMin= 0;
   double xOfMax= 0;


   // compute x & y that's basis for min/max comparison
   yprev= 15*sin(x)+cos(x)+16;

   // table of values
   for (x=0; x<= 10; x+= .5) {
      // calculate 
      ynew= 15*sin(x)+cos(x)+16;
      // min and max
      if (ynew>= yprev){
         yMax= ynew;
         xOfMax= x;
      } else if (ynew <= yprev) {
         yMin= ynew;
         xOfMin= x;
      }   


      // bar graph
      countDigits= 0;
      bar= "";
      while (countDigits<=(ynew-1)) {
         bar = bar +  "#";           // CITE: how to concatenate strings not automatically printing: www.cplusplus.com/reference/string/string/operator+/
         countDigits= countDigits +1;   
      }

      // display
      cout << right << setw(7) << x << setw(7) << ynew << "   " << setw(33) << left <<  bar << endl;

   }
   cout << "\nThe maximum of " << yMax << " was at x=" << xOfMax << "." << endl;
   cout << "The minimum of " << yMin << " was at x=" << xOfMin << "." << endl;

   return 0;
}

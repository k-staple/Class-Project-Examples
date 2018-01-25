// Lab 3, Part 1, section 3
// Kathryn Stapleton, Sept 11

#include <iostream>
using namespace std;

// prototype of function
int getgcd(int a, int b);

int main () {

   // intialize 
   int num1= 0;   // naming convention like explained before lab
   int num2= 0;

   // ask for input
   cout << "Of which two numbers would you like to find a common denominator?" << endl;
   cin >> num1 >> num2;

   //display
   cout << "The greatest common denominator is " << getgcd(num1, num2)<< "." << endl;
   

   return 0;
}

int getgcd(int a, int b) {
   int gcd =0;
   if (a==0) {
      gcd= b;
      return gcd;
   } else if (b== 0) {
      gcd= a;
      return gcd;
   } 
   
   // make sure first number is larger
   if (b>a) {
      int c =0;
      c=a;
      a=b; 
      b=c;
      gcd= 100;
   }
      
   // compute gcd for two nonzero numbers
   int multiple= 0;
   int remainder= 1;
   while (remainder!=0){
      multiple= a/b;                    // assume integer truncationo
      remainder= a-(multiple*b);
      a= b;
      b= remainder;
   }
   
   // when quite while
   gcd= a;

   return gcd;
   
}

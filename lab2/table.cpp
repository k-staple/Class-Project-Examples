// Lab 2, Part 1: Multiplication Table
// Kathryn Stapleton, Sept 4, 2017

#include <iostream>
using namespace std;

int main () {

   // initialize input variables
   int columns =0;
   int rows =0;

   // ask user for 2 integers
   cout << "How many columns do you want in your multiplication table? \n" ;
   cin >> columns;

   cout << "How many rows do you want in your multiplication table? \n";
   cin >> rows;

   // display multiplication table 
  
   // top line
   cout << "*";
   for (unsigned int counter= 1; counter <= (columns); ++ counter) {
      cout << "\t" << counter;
   }
   cout << "\n";

   // left header and main multiplication
   
   for (unsigned int j= 1; j <= rows; ++j) {   
      for (unsigned int i = 1; i  <= (columns+1); ++ i) {
         if (i == 1) {
            cout << j;
         }
      
         else {
            cout << "\t" << (i-1)*j;
         }
         
      }
      cout << "\n";
   }

   cout << "\n" << endl;

   // main multiplication part; REALIZED SHOULD DO LINES PAST FIRST ALL TOGETHER
   // for (unsigned int i=1; i<=rows; ++i) {
   //  cout << "\n" << "a";
   // }

   return 0;
}

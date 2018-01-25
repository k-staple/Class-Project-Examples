// Lab 3, Part 3 Menu Calc
// Kathryn Stapleton, section 3, Sept 16

#include <iostream>
using namespace std;

//prototypes
double addition (double a, double b);
double subtraction(double a, double b);
double multiplication(double a, double b);
double division (double a, double b);


int main () {

   // initialize variables
   int choice= 0;
   double num1= 0;
   double num2= 0;
   int go= 1;


   while (go==1) {
      // ask for input
      cout << "Please choose which operation you would like to compute with two numbers. \n 1 for addition \n 2 for subtraction \n 3 for multiplication \n 4 for division \n 5 to quit" << endl;
      cout << "Option chosen:  ";
      cin >> choice;

      if (choice==5) {
         cout << "Goodbye!" << endl;
         break;
      }
      if (choice<1 || choice>5) {
         continue;
      }

      cout << "Enter your two numbers:  ";
      cin >> num1 >> num2;

      // do the operation
      if (choice == 1) {
         cout << num1 << " + " << num2 << " = " << addition (num1, num2) << endl;
      } else if (choice == 2){
         cout << num1 << " - " << num2 << " = " << subtraction(num1,num2) <<endl;
      } else if (choice == 3){
         cout << num1 << " * " << num2 << " = " << multiplication(num1,num2) <<endl;
      } else if (choice == 4){
         cout << num1 << " / " << num2 << " = " << division(num1,num2) <<endl;
      }
   }

   return 0;
}


// functions
double addition (double a, double b) {
   double sum = a + b;
   return sum;
}

double subtraction (double a, double b) {
   double difference= a - b; // CITE: forgot what a-b was called :) mathsteacher.com.au/year8/ch01_arithmetic/01_basic/oper.htm
   return difference;
}

double multiplication (double a, double b) {
   double product= a * b;
   return product;
}

double division (double a, double b) {
   double quotient= a/b;
   return quotient;
}

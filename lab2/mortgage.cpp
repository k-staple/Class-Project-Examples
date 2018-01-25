// Fund Lab 2, Part 2 Mortgage Calculator
// Kathryn Stapleton, Sept 8, 2017

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main () {

   // tell computer to use two decimal places
   cout << fixed << setprecision(2);

   // initialize
   float balance= 0;
   float interestRate= 0;
   float payment=0;
   float interest= 0;
   int month= 0;        //tallies the months it takes to pay off loan
   float monthlyRate= 0;   //inputted interestRate divided by 12
   float totalPayment= 0;
   int years= 0;             // this and below to compute total time
   //  int totalMonths= 0;      
      // extraneous now that month is int-  need two int to do % 
   int numExtraMonths= 0;
   float testInterest= 0;  // this and below used to check if payment too small
   float testBalance= 0;


   //input & CHECK IF ACCEPTABLE NUMBER
   cout << "How much is your loan (the principal)? \n";
   cin >> balance;
   // CHECK IF NEGATIVE OR 0 
   while (balance<= 0) {
      cout << "Please enter a positive value for the amount borrowed: \n" << endl;
      cin >> balance;
   }
   

   cout << "What's the interest rate (as a decimal)? \n";
   cin >> interestRate;
   // CHECK IF A DECIMAL
      // CITE for identifying error using || : www.mathworks.com/matlabcentral/answers/50713-how-to-make-two-conditions-for-a-while-loop?requestedDomain=www.mathworks.com
      while (interestRate<= 0 ||interestRate >=1){
         cout << "Please enter the interest rate as a decimal between 0 and 1: " << endl;
         cin>> interestRate;
      }

   cout << "What's your desired monthly payment?" << endl;
   cin >> payment;
   // CHECK IF PAYMENT TOO SMALL	
   testInterest= balance*interestRate/12;
   testBalance= balance+ testInterest- payment;
   while (testBalance >= balance) {
      cout << "Please enter a number higher than $" << testInterest << endl;
      cin >> payment;
      testBalance= balance+ testInterest - payment;
   }   


   // amoritization table
   
   // header; setw specifies how wide the column is: using number of header characters + 3
   cout << "Month" << setw(10) << "Payment" << setw(10) << "Interest" << setw(10) << "Balance \n";

   /* need to include by horizontal line; can't write month & move back up to type
   calculating part of table */
  
   //monthly Rate stays the same
    monthlyRate= interestRate/12;

   for (unsigned int i=1; balance>0; i++){
      // calculate
      month= month + 1;
      interest= balance*monthlyRate;

      if (balance>payment) {
         balance= balance+ interest - payment;
      } else {
         totalPayment= (month-1)*payment + balance;
         payment= balance;
         balance= 0;
      }

      // display
      cout << setw(5) << month << setw(10) << payment << setw(10) << interest << setw(10) << balance << endl;
   }

   // calc total time
   years= month/12;
   //  totalMonths= month;  //extraneous now that month is int
   numExtraMonths= month % 12;

   // display how long and total payments
   cout << "\n You paid a total of $"<< totalPayment << " over " << years << " years and " << numExtraMonths << " months." << endl;
 

   return 0;
}

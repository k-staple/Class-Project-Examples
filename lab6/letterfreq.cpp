// Kathryn Stapleton, section 3
// Lab 6, Part 2, Letter Freq 10.13.2017

#include<iostream>
#include<array>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

const int size = 28; //26 letters, one white space, one punctuation/other
int sumLetters(array<int, size>&);

int main (){

   array<int, size> freq = {};

   //make connection
   ifstream ifs;
   string inputfile;
   cout << "What's the name of your file?" << endl;
   cin >> inputfile;

   ifs.open(inputfile);

   //check if valid
   if (!ifs) {
      cout << "error opening" << endl;
      return 1;
   }

   string str;
   getline(ifs,str);
  // freq[26]++;   //account for new line white space this getline skips
  // string oneSpot= str[place];
   while (!ifs.eof()){
      int place=0; 	//needs to reset for every phrase iterating thru
      freq[26]++;  //account for new line white space that getline skips
      for (auto it = str.begin(); it<str.end(); it++){
         if (isspace(*it ) ){  //don't need str[place]
            freq[26]++;
         } else if ((*it) >= 97 && (*it) <=122){
            freq[(*it)-97]++;
         }  else if ((*it) >=65 && (*it) <= 90){
            freq[(*it)-65]++;
         }  else {
            freq[27]++;
         }
         place++;
      }
      getline(ifs,str);
   }

   int n=97;
   int numOnLine= 1;
   for (auto it=freq.begin(); it<(freq.end()-2);it++){
     char a= n; 
     if (numOnLine==5){
       cout << left <<  a << left <<": " << setw(8) << left << *it;
       cout << endl;
       numOnLine= 1;
     } else if (numOnLine<= 4){
        cout <<left<< a << left <<  ": " << setw(8) << left << *it;
        numOnLine ++;
     } 
     n++;
   }
   cout << endl;
   double s= sumLetters(freq);
   double whiteSpace= freq[26];
   double  total= s + whiteSpace + freq[27]; //27 has misc char
   cout << fixed << setprecision (0);
   cout << "There are " << s << " total letters." << 
endl;
   cout << "There are " << total << " total characters." << 
endl;
   cout << "There are " << whiteSpace << " white space characters." << 
endl;
   cout << setprecision(1);
   cout << "space percentage: " << whiteSpace/total*100 << "%" << endl; 

   return 0;
} 

int sumLetters(array<int, size>& arr){
   int sum= 0;
   int i;
   for (i=0 ; i<=25; i++){
      sum+= arr[i];
   }
   return sum;
}

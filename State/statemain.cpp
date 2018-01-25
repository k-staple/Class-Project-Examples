//Kathryn Stapleton, section 3, 10/29
// Lab 7, Part 2 State class
// main

#include <iostream>
#include <fstream>
#include <vector>
// string, namespace in header

#include "state.h"

//prototypes
int display(vector<State> &);        
int atLeastRep(vector<State> &);
int update(vector<State> &);
void age(vector<State> &);

int main () {
  // read in file: establish connection, check if it's valid
  ifstream ifs;
  string userFilename;
  string abbrev, name, cap, pop_s, yr_s, numRep_s;
  int pop, yr, numRep;
  vector<State> allStates;
  State oneState;

  cout << "Please enter data file name: "; 
  cin >> userFilename;
  ifs.open(userFilename);
  if (!ifs) {
    cout << userFilename << " is an invalid choice" << endl;
    return 1;
  }

  while(ifs.peek() !=EOF){
     getline(ifs, abbrev, ',');
     getline(ifs, name, ',');
     getline(ifs, cap, ',');
     getline(ifs, pop_s, ',');
     getline(ifs, yr_s, ',');
     getline(ifs, numRep_s, '\n');
     pop= stoi(pop_s);
     yr= stoi(yr_s);
     numRep= stoi(numRep_s);
     oneState= State(abbrev, name, cap, pop, yr, numRep);
     allStates.push_back(oneState);
  }

  // menu
  int go = 1;
  int choice=0;
  while (go==1){
    cout << "Choose an option\n" <<
    "1: Display a state's age\n" << 
    "2: Display States who have at least a certain number of representatives\n"
    << "3: Update a certain state's number of representatives record\n" <<
    "4: Quit" << endl;
    cin >> choice;

    if (choice< 1 || choice > 4) continue;
    
    switch (choice) {
      case 4: 
        cout << "Goodbye!" << endl;
        go = 0;
        break;
      case 1:
         age(allStates);
        break;
      case 2:
        atLeastRep(allStates);
        break;
      case 3:
         update(allStates);
         break;
      default:
        cout << "undefined";
      }
  }
  return 0;
}

void age(vector<State> &s){
  int yearInput, oldYear;
  string ageState;
  cout << "What's the year?" << endl;
  cin >> yearInput;
  cout << "What state do you want to date?" << endl;
  cin >> ageState;
  for (auto it=s.begin(); it !=s.end(); it++){
    if (it->getName() == ageState) {
       oldYear= it->getYr();
       cout<< yearInput-oldYear;
    }
  }
}

int atLeastRep(vector<State> &s){
  int repNumChoice=0;  
  cout << "What's the minimum number of representatives? (up to 53)" << 
endl;
  cin >> repNumChoice;
  if (repNumChoice<1 || repNumChoice > 53) return 0;
  for (auto it=s.begin(); it !=s.end(); it++) {
    if(it->getNumRep() >= repNumChoice){
      cout << it->getName() << endl;
    }
  }
  return 0;
}

int update(vector<State> &s){
  int newNum=0;
  string updateState;
  cout << "What state has a new number of representatives?" << endl;
  cin >> updateState;
  cout << "How many does "<< updateState << " have now?" << endl;
  cin >> newNum;
  if (newNum < 1) {
    cout << updateState << " has to have at least one. Invalid choice." 
    << endl;
    return 0;
  }
  for (auto it=s.begin(); it != s.end(); it++){
    if (it->getName() == updateState) {
       it->setNumRep(newNum);
    }
  }

return 0;
}

/*int display(vector<State> &s)
{
  int choice2=0;  
  cout << "States and \n" <<
  "1: their capitals\n2: their populations\n3: years they became a state" << 
  "\n4: number of representatives in Congress" << endl;
  cin>> choice2;
  if (choice2<1 || choice2>4) {
    cout << "invalid choice" << endl;
    return 0;
  } 
  switch (choice2){
    case 1:
      #define CHANGING_CALL Cap
      break;
    case 2:
      #define CHANGING_CALL Pop 
      break;
    case 3:
       #define CHANGING_CALL Yr
       break;
    case 4:
       #define CHANGING_CALL NumRep
       break;
    default: 
       cout << "invalid" << endl;
  }
  for (auto it=s.begin(); it!=s.end(); it++){
    cout << it->getName() << " (" << it->getAbbrev() << ") ," << 
    it->getCHANGING_CALL() << endl;
  }
  #undef CHANGING_CALL
  return 0;
}
*/

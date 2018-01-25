//Kathryn Stapleton, section 3, Oct 8
//Lab 5, Part 2 Sayings Manager

#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

void display(list<string>);
void add(list<string>&);
void find(list<string>);
int saveNew(list<string>); //returns 2 if output connection not successful
void remove(list<string>&);//need to pass by ref because changing the list

int main () {

   // declare variables
   list<string> compilation;

   //read in startup file; "ifstream object connects to a data file"
   ifstream ifs;
   string thefile;

   cout << "Please enter the name of your desired file:  " << endl;
   cin >> thefile;

   ifs.open(thefile);

   //check if valid
   if (!ifs) {
      cout << "error opening" << endl;
      return 1;
   }

   //load in sayings. Use getline so put whole saying in one string
   string str;
   getline(ifs, str);      //reads only one line

   int i=0;  		//a counter
   while (!ifs.eof()) {
      compilation.push_back(str);
      i++;
      getline(ifs, str);
   }   

   // sort compilation
   compilation.sort();

int go=1;
while (go==1){
   int choice=0;
   cout << "Please select from the following: " <<
   "\n1: Display all sayings" <<
   "\n2: Add a new saying" <<
   "\n3: Search for all sayings that contain what you're looking for" <<
   "\n4: Save all sayings in new text file" <<
   "\n5: Remove a saying" <<
   "\n6: Quit" << endl;
   cin >> choice;

   switch (choice) {
      case 6:
         cout << "Goodbye!" << endl;
         go = 0;
         break;
      case 1: 
          display(compilation);
          break;
      case 2:
          add(compilation);
          break;
      case 3:
          find(compilation);
          break;
      case 4:
          saveNew(compilation);
          break;
      case 5:
          remove(compilation);
          break;
   }

}

   return 0;
}


void display(list<string> vOfStrings) {
   int n= 1;
   for (auto it= vOfStrings.begin(); it != vOfStrings.end(); it++){
      cout << n << ": " << *it << endl;
      n ++;
   }
}

void add(list<string>& vOfStrings) {
   string strAdded;
   cout << "Enter the saying you would like to add:  " << endl;
   cin.ignore();
   getline(cin, strAdded);
   cout << strAdded[0];
   vOfStrings.push_back(strAdded);
   vOfStrings.sort();
}

void find(list<string> vOfStrings){
   string findPhrase;
   cout << "Enter the phrase you'd like to find: ";
   cin >> findPhrase;
   for (auto it= vOfStrings.begin(); it != vOfStrings.end(); it++){
      size_t found = (*it).find(findPhrase);
      if (found!= std::string::npos){
         cout << *it << endl;
      }
   }

}

int saveNew(list<string> vOfStrings){
   string filenameOutput;
   ofstream ofs; 			// have to declare ofstream obj
   cout << "Enter what you would like to save your new file as: "<<endl;
   cin >> filenameOutput;
   ofs.open(filenameOutput);

   if (!ofs) {
      cout << "error saving file as " << filenameOutput << endl;
      return 2;
   }
   
   for (auto it= vOfStrings.begin(); it != vOfStrings.end(); it++){
      ofs << *it << endl;
   }
   return 0;
}

void remove(list<string>& lOfStrings){
   int removeChoice;
   cout << "Here are the available sayings." << endl;
   display(lOfStrings);
   cout << "What's the number of the saying you want to delete?: " << 
   endl; 
   cin >> removeChoice;
   list<string>::iterator it;
   it= lOfStrings.begin();
   advance (it, (removeChoice-1));
   lOfStrings.erase(it);

}

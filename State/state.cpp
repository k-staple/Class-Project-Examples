// Kathryn Stapleton, section 3, 10/29
// Lab 7, Part 2, State class
// implementation

#include "state.h" 
using namespace std;

State::State() {}
State::State(string abbreviation, string stateName, string capital, int population, int year, int rep)
{ abbrev= abbreviation; name = stateName; cap = capital; 
  pop= population; yr= year; numRep= rep; }

State::~State() {}

void State::setAbbrev(string abbreviation)
{ abbrev= abbreviation; }

void State::setName(string stateName)
{ name= stateName; }

void State::setCap(string capital)
{ cap= capital; }

void State::setPop(int population)
{ pop= population; }

void State::setYr(int year)
{ yr= year; }

void State::setNumRep(int rep)
{ numRep = rep; }

string State::getAbbrev()
{ return abbrev; }

string State::getName()
{ return name;}

string State::getCap()
{ return cap;}

int State::getPop()
{ return pop; }

int State::getYr()
{ return yr; }

int State::getNumRep()
{ return numRep; }

/*void State::display(vector<State> &s)
{ 
  cout << "For a listing of states with a certain characteristic, \n" <<
  "1: capital\n2: population\n3: year it became a state\n" << 
  "4: number of Representatives in Congress" << endl;
  for (auto it=s.begin(); it!= s.end(); it++) {
    cout << it->getName() << " (" ;
    cout << it-> getAbbrev() << ") : " << endl;
  }
}
*/

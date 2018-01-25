// Kathryn Stapleton, section 3, 10/29
// Lab 7, Part 2, State class
// interface

#include <string>
using namespace std;

class State {
  public: 
    State();
    State(string, string, string, int, int, int);
    ~State();
    void setAbbrev(string);
    void setName(string);
    void setCap(string); //capital
    void setPop(int); //population
    void setYr(int);
    void setNumRep(int);
    string getAbbrev();
    string getName();
    string getCap();
    int getPop();
    int getYr();
    int getNumRep();
//    void display(vector<State> &s); //decided against using
  private:
    string abbrev;
    string name;
    string cap;
    int pop;
    int yr;
    int numRep;
};          

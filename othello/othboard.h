// Kathryn Stapleton, Lab 9
// interface
#include <iostream>
#include <array>
#include <string>
using namespace std;
#define BOARD_SIZE 4

class Othboard {
  friend ostream& operator<<(ostream&, Othboard &);
  public:
    Othboard ();
    ~Othboard ();
    int checkNeighbor(int, int);
    void swap(int, int, char curPlayer, char oppPlayer);
    void piece(char, int, int);
    char winner();
  private:
    array< array< char, BOARD_SIZE> , BOARD_SIZE> board;
};

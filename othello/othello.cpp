// Kathryn Stapleton, section 3
// driver
#include "othboard.h"
#include <cstdlib> // using system as in system("clear")

int main (){
  Othboard setup;
  char curPlayer; // current Player
  char oppPlayer;
  int x, y, hasNeighbor;

  cout << setup;
  cout << "Choose coordinates by typing x-coord ycoord and hitting enter" << endl;
  for (int runs= 0; runs < BOARD_SIZE* BOARD_SIZE -4; runs++){
    hasNeighbor=0;
    curPlayer=(runs/2==(runs+1)/2)?'X':'O';
    oppPlayer=(runs/2==(runs+1)/2)?'O':'X';
    cout << "player " << curPlayer << " moves: ";
    cin >> x >> y;
    hasNeighbor= setup.checkNeighbor(x,y);
    while (hasNeighbor==0){
      cout << "Please enter a position adjacent to a current piece." << endl;
      cout << "player " << curPlayer << " moves: ";
      cin >> x >> y;
      hasNeighbor= setup.checkNeighbor(x,y);
    }    
    setup.piece(curPlayer, x,y);
    setup.swap(x, y, curPlayer, oppPlayer);
    system ("clear");
    cout << setup;
  }
  if (setup.winner() == 'T') {
    cout << "Players X and O tied." << endl;
  }  else {
    cout << "Player " << setup.winner() << " won." << endl;
  }  
} 

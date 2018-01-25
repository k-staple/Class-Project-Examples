// implementation, Othello

#include "othboard.h"

Othboard::Othboard()
{ for (auto it= board.begin(); it< board.end(); it++) {
     for (auto it2= (*it).begin(); it2 != (*it).end(); it2++) {
       (*it2) = '.';
     }
   }
  board[(BOARD_SIZE/2)-1][(BOARD_SIZE/2)-1]='X';
  board[(BOARD_SIZE/2)-1][(BOARD_SIZE/2)]='O';
  board[(BOARD_SIZE/2)][(BOARD_SIZE/2)-1]='O';
  board[(BOARD_SIZE/2)][(BOARD_SIZE/2)]='X';

}

Othboard::~Othboard(){}

int Othboard::checkNeighbor(int x, int y)
{ int rowSpot=y; int colSpot= x;
  if (rowSpot<0 || rowSpot >= BOARD_SIZE || colSpot<0 || colSpot >= BOARD_SIZE){
    cout << "That position is not on the board." << endl;
    return 0;
  }
  if (board[rowSpot][colSpot]!='.'){
    cout << "A piece has already been placed at that position." << endl;
    return 0;
  }
  for (int row= rowSpot-1; row <= rowSpot+1; row++) {
    for (int col= colSpot-1; col <= colSpot+1; col ++ ) {
      //if this spot exists and isn't the user's choice
      if (row>=0 && row <BOARD_SIZE && col >=0 && col < BOARD_SIZE && !(row==rowSpot && col == colSpot)) {
        if (board[row][col] != '.'){
          return 1;
        }
      }
    }
   }
  return 0;
}

void Othboard::swap(int x, int y, char curPlayer, char oppPlayer)
{ int rowChange, colChange, hitCurrent, loopRow, loopCol;
  int moreThan1Opp;
  int rowSpot=y; int colSpot= x;
  for (int row= rowSpot-1; row <= rowSpot+1; row++) {
    for (int col= colSpot-1; col <= colSpot+1; col ++ ) {
      //if this spot exists and isn't the user's choice
      if (row>=0 && row <BOARD_SIZE && col >=0 && col < BOARD_SIZE && !(row==rowSpot && col == colSpot)) {
        if (board[row][col] == oppPlayer){
          rowChange= row-rowSpot;
          colChange= col-colSpot;
          hitCurrent=0;
          moreThan1Opp=0;
          loopRow= row+ rowChange;
          loopCol= col + colChange;
          while (hitCurrent==0 && loopRow>= 0 && loopRow <=BOARD_SIZE && loopCol >= 0 && loopCol <= BOARD_SIZE) {
            if (board[loopRow][loopCol]== oppPlayer){
              loopRow += rowChange; //starts from two away since know adj is opposing player
              loopCol += colChange;
              moreThan1Opp ++;
            } else if (board[loopRow][loopCol]==curPlayer){
              hitCurrent=1;
              // move backwards to original placed piece & flip until then
              for(int towardsPlacedPiece = 0; towardsPlacedPiece < 1+moreThan1Opp; towardsPlacedPiece ++){
                loopRow = loopRow - rowChange;
                loopCol= loopCol - colChange;
                piece(curPlayer, loopCol, loopRow);
              }

            } else {
              break;
            }
            
          }
         }
       }
     }
   }

}



void Othboard::piece(char A, int x, int y)
{ board[y][x]=A;

}

char Othboard::winner()
{ int XCounter=0, OCounter= 0;
  for (auto it= board.begin(); it< board.end(); it++) {
     for (auto it2= (*it).begin(); it2 != (*it).end(); it2++) {
       if((*it2) == 'X'){
         XCounter ++;
       } else if ((*it2) == 'O'){
         OCounter ++;
       }
     }
   }
   if (XCounter==OCounter) {
     return 'T';
   } else {
   return (XCounter>OCounter)? 'X':'O';
   }
} 

ostream& operator<<(ostream &s, Othboard &t)
{ int i=0, j=0; //counter for printing of actual board, not labels
  s <<  " "; 
  for (int topLabel=0; topLabel<= BOARD_SIZE-1; topLabel++){
    s << topLabel;
  }
  s << endl; 
  for (int sideLabel=0; sideLabel<= BOARD_SIZE-1; sideLabel++){
    s << sideLabel;
    for (j=0; j<= BOARD_SIZE-1; j++){
      s << t.board [i][j];
    }
    i++;
    s << endl;
  }

}
  

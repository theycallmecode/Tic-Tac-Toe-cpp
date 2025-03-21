// creating a tic tac toe game using c++

#include<iostream>
using namespace std;



// display the board
void displayBoard(char board[3][3]) {
   // cout<<endl;

   for(int i=0; i<3; i++) {
      for(int j=0; j<3; j++) {
         cout<<board[i][j]<<" ";
      }
      cout<<endl;
   }
}

// function to check board results
int checkBoard(char board[3][3]) {

   return 0;
}

// function to take input in tic tac toe
int takeInput(char board[3][3], int turns) {
   int row, col;
   cout << "Enter row & column (0-2): ";
   cin >> row >> col;

   if(turns%2!=0) {
      board[row][col]='X';
   } else {
      board[row][col]='O';
   }

   // condition check to win or draw
   if(turns<4) {
      checkBoard(board);
   }

   return 0;
}

// function to fill the board with space
void fillBoard(char board[3][3]) {
   for(int i=0; i<3; i++) {
      for(int j=0; j<3; j++) {
         board[i][j]=' ';
      }
   }
}

int main() {
   char board[3][3];
   int turns = 9;
   fillBoard(board);

   for( int i=1; i<=9; i++ ) {
      turns++;
      takeInput(board, turns);
      // display function
      displayBoard(board);
   }

   return 0;
}
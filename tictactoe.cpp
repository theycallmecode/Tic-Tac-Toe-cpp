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

// function to take input in the board
int takeInput(char board[3][3], int turns) {
   int row, col;
   cout << "Enter row & column (0-2): ";
   cin >> row >> col;

   if(turns%2==0) { // player 2 turn
      board[row][col]='X';
   }
   else { // player 1 turn
      board[row][col]='O';
   }

   // function call to check the board status
   if(turns<4) {
      
      // to check
      cout<<"Yes";
      checkBoard(board);
   }

   return 0;
}

// function to play the game 
void toPlay(char board[3][3], int turns) {
   // loop to take input in the board
   for( int i=1; i<9; i++ ) {
      takeInput(board, turns);

      // fucntion call to display function
      displayBoard(board);
      turns++;
   }
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
   // declare a matrix 3x3 for the game 
   char board[3][3];
   int turns = 1; // count the number of turns

   // fucntion to fill the board with empty spaces
   fillBoard(board);

   //function to play the game
   toPlay(board, turns);

   for( int i=1; i<=9; i++ ) {
      turns++;
      takeInput(board, turns);
      // display function
      displayBoard(board);
   }

   return 0;
}
// creating a tic tac toe game using c++

#include<iostream>
using namespace std;

// function declarations
void displayBoard(char board[3][3]);
void fillBoard(char board[3][3]);
void toPlay(char board[3][3]);
int takeInput(char board[3][3]);
void checkBoard(char board[3][3]);


// global variables
int turns = 1; // keeps track of turns
bool game = false; // game status
int i=0, j=0; // loop counters


int main() {
   // declare a 3x3 matrix for the game 
   char board[3][3];

   // fucntion call to fill the board with empty spaces
   fillBoard(board);

   // function call to start the game
   toPlay(board);

   if(game) cout<<endl<<"Player WINS";
   else cout<<endl<<"DRAW";

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


// function to start the game 
void toPlay(char board[3][3]) {
   // loop to take input in the board
   for( int i=1; i<=9; i++ ) {
      takeInput(board);

      // fucntion call to display the game board
      displayBoard(board);
      turns++;
   }
}


// function to take input in the board
int takeInput(char board[3][3]) {
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
   if(turns>4) {
      checkBoard(board);
   }

   return 0;
}


// display the board
void displayBoard(char board[3][3]) {
   for(int i=0; i<3; i++) {
      for(int j=0; j<3; j++) {
         cout<<board[i][j]<<" ";
      }
      cout<<endl;
   }
}


// function to check the board status
void checkBoard(char a[3][3]) {

   // check rows
   i=0,j=0; // reset loop counters
   while(i<2) {
      while(j<1) {
         if ( a[i][j] == ' ' ) {
            continue;
         }
         else if(a[i][j]==a[i][j+1] && a[i][j]==a[i][j+2]) {
            game = true;
            return ;
         }
         j++;
      }
      i++;
   }
   
}
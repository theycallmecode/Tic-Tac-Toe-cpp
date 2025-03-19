// creating a tic tac toe game using c++

#include<iostream>
using namespace std;

// function to take input in tic tac toe
int takeInput(char board[3][3]) {
   int row, col;
   cout << "Enter row (0-2): ";
   cin >> row;
   cout << "Enter column (0-2): ";
   cin >> col;
   return 0;
}

int main() {
   char board[3][3];
   int turns = 9;

   for( int i=1; i<=9; i++ ) {
      takeInput(board);
   }

   return 0;
}
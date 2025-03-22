#include <iostream>
using namespace std;


// Function declarations
void fillBoard(char board[3][3]);
void displayBoard(char board[3][3]);
bool makeMove(char board[3][3], int player);
bool checkWin(char board[3][3], char symbol);
bool isBoardFull(char board[3][3]);
void playGame();


int main() {
   cout << "Welcome to Tic Tac Toe!\n";
   cout << "Player 1 = 'X', Player 2 = 'O'\n";

   playGame();

   return 0;
}


// game logic here
void playGame() {
   char board[3][3];
   fillBoard(board);
   int currentPlayer=1;
   bool gameWon = false;

   while(!gameWon && !isBoardFull(board)) {
      displayBoard(board);

      // Keep asking for input until a valid move is made
      while (!makeMove(board, currentPlayer)) {
         // Loop until valid move
      }

      // Check for win after move
      char symbol = (currentPlayer == 1) ? 'X' : 'O';

      if (checkWin(board, symbol)) {
         displayBoard(board);
         cout << "Player " << currentPlayer << " wins!\n";
         gameWon = true;
      }
      else {
         currentPlayer = (currentPlayer == 1) ? 2 : 1; // Switch players
      }
   }

   // If no one wins and board is full, it's a draw
   if(!gameWon) {
      displayBoard(board);
      cout << "It's a draw!\n";
   }

   // Ask to play again
   char playAgain;
   cout << "Play again? (y/n): ";
   cin >> playAgain;

   if (playAgain == 'y') {
      playGame(); // Recursive call to restart
   }
   else {
      cout << "See You Next Time!\n";
   }
}


// Initialize the board with empty spaces
void fillBoard(char board[3][3]) {
   for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++) {
         board[i][j] = ' ';
      }
   }
}


// Display the board
void displayBoard(char board[3][3]) {
   for(int i=0; i<3; i++) {
      for(int j=0; j<3; j++) {
         cout << board[i][j] << " ";
      }
      cout << endl;
   }
}

// Handle player move with input validation
bool makeMove(char board[3][3], int player) {
   char symbol = (player == 1) ? 'X' : 'O';
   int row, col;

   cout<<"Player "<<player<<" ("<<symbol<<"), enter row and column (0-2): ";
   cin >> row >> col;

   // check valid input
   if (cin.fail() || row < 0 || row > 2 || col < 0 || col > 2) {
      cin.clear(); // Clear error state
      cin.ignore(10000, '\n'); // Discard invalid input
      cout << "Invalid input!\n";
      return false;
   }

   // Check if the cell is available
   if (board[row][col] != ' ') {
      cout << "Cell already taken!\n";
      return false;
   }

   board[row][col] = symbol;
   return true;
}

// Check if the current player has won
bool checkWin(char board[3][3], char symbol) {
   // Check rows
   for (int i = 0; i < 3; i++) {
      if (board[i][0]==symbol && board[i][1]==symbol && board[i][2]==symbol) {
         return true;
      }
   }

   // Check columns
   for (int j=0; j<3; j++) {
      if (board[0][j]==symbol && board[1][j]==symbol && board[2][j]==symbol) {
         return true;
      }
   }

   // Check diagonals
   if(board[0][0]==symbol && board[1][1]==symbol && board[2][2]==symbol) {
      return true;
   }
   if(board[0][2]==symbol && board[1][1]==symbol && board[2][0]==symbol) {
      return true;
   }

   // if no cases hit true
   return false;
}


// Check if the board is full (draw condition)
bool isBoardFull(char board[3][3]) {
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         if (board[i][j] == ' ') {
            return false; // Found an empty spot
         }
      }
   }
   return true; // No empty spots
}
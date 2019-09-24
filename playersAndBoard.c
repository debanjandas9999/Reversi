#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

  typedef struct player {
    char name[20]; // Stores the names of players
    int pieceType; // Used to determine the type of piece assigned to users. 1 denotes dark and 0 denotes white
    int pieces; // Represents the pieces present on board
  }player;

void playerDetails(player player1, player player2){
  player1.pieces = 2;
  player2.pieces = 2; //in the beginning there are 2 of each on board

  printf("Enter name of player 1\n");
  fgets(player1.name, 20, stdin); // Name of the first player accepted from the user
  printf("Enter name of player 2\n");
  fgets(player2.name, 20, stdin); // Name of the second player accepted from the user

  //code to remove possible new line character that can occur in fgets
  size_t len = 0;
  len = strlen(player1.name);
  if ((len > 0) && (player1.name[len - 1]) == '\n')
    player1.name[len - 1] = '\0';
  len = strlen(player2.name);
  if ((len > 0) && (player2.name[len - 1]) == '\n')
    player2.name[len - 1] = '\0';


    player1.pieceType = 1;
    player2.pieceType = 0;
    printf("%s (player 1) plays black (1) and %s (player 2) plays white (0)\n", player1.name, player2.name);
}

void initializeBoard(int board[8][8]){
    int i,j;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if ((i == 3 && j == 3) || (i == 4 && j == 4)) //placing two black pieces in the centre diagonal of board
      {
        board[i][j] = 1;
      } else if ((i == 3 && j == 4) || (i == 4 && j == 3)) //placing two white pieces in other centre diagonal of board
      {
        board[i][j] = 0;
      } else //empty squares on board
      {
        board[i][j] = 9; //using 9 instead of x since it is an integer array
        //9 is a unique digit since it in not appearing anhywhere else on the board
      }
    }
  }
}

void printBoard(int board[8][8]) {
  int i, j;
  printf("\n   ");
  for (i = 0; i < 8; i++) {
    printf("%d   ", i + 1);
  }
  for (i = 0; i < 8; i++) {
    printf("\n%d | ", i + 1);
    for (j = 0; j < 8; j++) {
      if (board[i][j] == 9)
        printf("x | ");
      else
        printf("%d | ", board[i][j]);
    }
  }
}

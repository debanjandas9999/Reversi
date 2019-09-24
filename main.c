//Reversi/Othello - the board game created by Ankish Raj Prajapati (17202456) and Debanjan Das (17202833)


#include < stdio.h > #include < stdlib.h > #include "gameLogicAndResult.h"

int main(void) {
  //instances of struct for both players created
  struct player player1 = {"Player 1",1,2};
  struct player player2 = {"Player 2",0,2};

  playerDetails(player1, player2);

  int board[8][8];

  initializeBoard(board);

  printBoard(board);

  logic(player1, player2, board);
}

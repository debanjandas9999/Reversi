#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
typedef struct player {
    char name[20]; // Stores the names of players
    int pieceType; // Used to determine the type of piece assigned to users. 1 denotes dark and 0 denotes white
    int pieces; // Represents the pieces present on board
  }player;

void result(player player1, player player2) {
  if (player1.pieces > player2.pieces) {
    printf("\n*************\nThank you for playing\nThe winner is player 1\n*************\n");
  } else if (player1.pieces < player2.pieces) {
    printf("\n*************\nThank you for playing\nThe winner is player 2\n*************\n");
  } else
    printf("\n*************\nThank you for playing.\nThe game ended in a draw.\n*************\n");
}

void logic(player player1, player player2, int board[8][8]) {
  int turn = 1;
  int i, j, x, y, k, l;
  int master = -1, flag1 = 0, flag2 = 0, flag3 = 0;
  int moves[20];
  while ((player1.pieces + player2.pieces) != 64) {
    do {
      if (master == -1) {
        printf("\n\n");
        if (turn == 1)
          printf("Player 1 please choose your next move\n");
        else
          printf("Player 2 please choose  your next move\n");

        printf("The possible moves are:\n");
        int a = 0;
        for (i = 0; i < 8; i++) {
          for (j = 0; j < 8; j++) {
            if ((board[i][j] == 0 && turn == 1) || (board[i][j] == 1 && turn == 0)) {
              x = i;
              y = j;
              int x1 = x + 1;
              int y1 = y + 1;
              int x2 = x - 1;
              int y2 = y - 1;
              if (x == 0)
                x2 = x;
              if (x == 7)
                x1 = x;
              if (y == 0)
                y2 = y;
              if (y == 7)
                y1 = y;

              for (k = x2; k <= x1; k++) {
                for (l = y2; l <= y1; l++) {
                  int xx = k;
                  int yy = l;

                  if (board[xx][yy] == 9) {
                    int diff_x = x - xx;
                    int diff_y = y - yy;
                    int x3 = x;
                    int y3 = y;

                    while (x3 < 8 && x3 >= 0 && y3 < 8 && y3 >= 0) {
                      if ((board[x3][y3] == 1 && turn == 1) || (board[x3][y3] == 0 && turn == 0)) {

                        for (int z = 0; z < 20; z++) {
                          if ((yy + 1 + ((xx + 1) * 10)) == moves[z])
                            flag1 = 1;
                        }
                        if (flag1 == 0) {
                          printf("%d,%d  ", xx + 1, yy + 1);
                          moves[a] = yy + 1 + ((xx + 1) * 10);
                          a++;
                        }
                        break;
                      } else if (board[x3][y3] == 9)
                        break;
                      x3 = x3 + diff_x;
                      y3 = y3 + diff_y;
                    }
                  }
                  flag1 = 0;
                }
              }
            }
          }
        }
      }

      int x4;
      int y4;

      if (moves[0] == 0) {
        printf("No possible moves!\nPassing...\n");
        break;
      }
      printf("\nEnter co-ordinates of the move you want to make\n");
      scanf("%d", & x4);
      scanf("%d", & y4);
      for (int q = 0; q < 20; q++) {
        if ((y4 + x4 * 10) == moves[q])
          flag2 = 1;
      }
      x4 = x4 - 1;
      y4 = y4 - 1;
      if (flag2 == 0) {
        printf("Invalid Input\n");
        master = 0;
      } else {
        if (turn == 1) {
          if (board[x4][y4] != 1) {
            board[x4][y4] = 1;
            player1.pieces = player1.pieces + 1;
          }
        } else {
          if (board[x4][y4] != 0) {
            board[x4][y4] = 0;
            player2.pieces = player2.pieces + 1;
          }
        }
        int x_adj1 = x4 + 1;
        int x_adj2 = x4 - 1;
        int y_adj1 = y4 + 1;
        int y_adj2 = y4 - 1;
        if (x4 == 0)
          x_adj2 = x4;
        if (x4 == 7)
          x_adj1 = x4;
        if (y4 == 0)
          y_adj2 = y4;
        if (y4 == 7)
          y_adj1 = y4;

        for (int k = x_adj2; k <= x_adj1; k++) {
          for (int z = y_adj2; z <= y_adj1; z++) {
            int x5 = k;
            int y5 = z;
            if ((board[x5][y5] == 0 && turn == 1) || (board[x5][y5] == 1 && turn == 0)) {
              int x6 = x5 - x4;
              int y6 = y5 - y4;

              while (x5 < 8 && x5 >= 0 && y5 < 8 && y5 >= 0) {
                if ((board[x5][y5] == 1 && turn == 1) || (board[x5][y5] == 0 && turn == 0)) {
                  flag3 = 1;
                  break;
                } else if (board[x5][y5] == 9)
                  break;
                x5 = x5 + x6;
                y5 = y5 + y6;
              }
              if (x5 < 0 || x5 >= 8)
                x5 = x5 - x6;
              if (y5 < 0 || y5 >= 8)
                y5 = y5 - y6;
              int x7 = x4;
              int y7 = y4;
              if (flag3 == 1) {
                x7 = x7 + x6;
                y7 = y7 + y6;
                master = 1;
                while ((x7 != x5 && y7 != y5) || (x7 == x5 && y7 != y5) || (x7 != x5 && y7 == y5)) {
                  if (turn == 1) {
                    board[x7][y7] = 1;
                    player1.pieces = player1.pieces + 1;
                    player2.pieces = player2.pieces - 1;
                  } else {
                    board[x7][y7] = 0;
                    player1.pieces = player1.pieces - 1;
                    player2.pieces = player2.pieces + 1;
                  }
                  x7 = x7 + x6;
                  y7 = y7 + y6;
                }
              }

            }
            flag3 = 0;
            master = 1;
          }
        }
      }
      flag2 = 0;

    } while (master != 1);
    printBoard(board);
    printf("\nNumber of blacks: %d\n", player1.pieces);
    printf("Number of whites: %d\n", player2.pieces);
    master = -1;

    for (int z = 0; z < 20; z++)
      moves[z] = 0;
    if (turn == 1)
      turn = 0;
    else
      turn = 1;
  }
  result(player1, player2);
}

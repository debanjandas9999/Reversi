#ifndef playersAndBoard_h //header guard
#define playersAndBoard_h
typedef struct player {
    char name[20]; // Stores the names of players
    int pieceType; // Used to determine the type of piece assigned to users. 1 denotes dark and 0 denotes white
    int pieces; // Represents the pieces present on board
  }player;
#endif // playersAndBoard_h
void playerDetails(player player1, player player2);
void initializeBoard(int board[8][8]);
void printBoard(int board[8][8]);


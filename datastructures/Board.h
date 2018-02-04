#ifndef STOCKLION_BOARD_H
#define STOCKLION_BOARD_H

#include "pieces/Piece.h"

class Board {
private:
    Color playerColor;

    //The array is 9x9 because we want to use indices 1 to 8 in each dimension
    Piece *board[9][9];

    void initState();

public:
    //Takes color of our player
    explicit Board(Color &playerColor);

    //Returns false if the move is not valid, otherwise returns true
    bool movePiece(Position &initPos, Position &destPos, Color player);

    //Checks to see if the move is valid for the given player
    bool isMoveValid(Position &initPos, Position &destPos, Color player);

    std::vector<Position> validMovesOfPiece(Position &piecePos);

    //Checks for the winner in the current state.
    //Returns null if none of the players won, otherwise returns the color of the winner.
    Color *whoWon();
};


#endif //STOCKLION_BOARD_H

//
// Created by Yashar Dabiran on 2018-02-03.
//

#ifndef STOCKLION_BOARD_H
#define STOCKLION_BOARD_H

#include "pieces/Piece.h"

class Board {
private:
    Color playerColor;
    Piece board[8][8];

    void initState();

public:
    //Takes color of our player
    explicit Board(Color &playerColor);

    void movePiece(Position &initPos, Position &destPos);
    bool isMoveValid(Position &initPos, Position &destPos);
    std::vector<Position> validMovesOfPiece(Position &piecePos);

    //Checks for the winner in the current state.
    //Returns null if none of the players won, otherwise returns the color of the winner.
    Color whoWon();
};


#endif //STOCKLION_BOARD_H

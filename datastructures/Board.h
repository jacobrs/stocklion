#ifndef STOCKLION_BOARD_H
#define STOCKLION_BOARD_H

#include "pieces/Piece.h"
#include <iostream>

class Board {
private:
    Color playerColor;

    // The array is 9x9 because we want to use indices 1 to 8 in each dimension
    Piece *board[9][9];

    void initState();

public:
    // Takes color of our player
    explicit Board();
    explicit Board(Color playerColor);

    // Returns false if the move is not valid, otherwise returns true
    bool movePiece(Position &initPos, Position &destinationPosition, Color player);

    // Checks to see if the move is valid for the given player
    bool isMoveValid(Position &initPos, Position &destinationPosition, Color player);

    std::vector<Position> validMovesOfPiece(Position &piecePos);

    // Place a piece on the board (should be used by converters only)
    void placePiece(Position pos, Piece *p);
    void setPlayerColor(Color c);
    void wipeBoard();

    // Gets a specific piece from the board
    Piece* getPiece(Position) const;

    // Print the board in an easy to read way
    void printBoard();
    void printUnicodeBoard();

    // Comparators
    bool operator==(const Board &other) const;
    bool operator!=(const Board &other) const;
};


#endif //STOCKLION_BOARD_H

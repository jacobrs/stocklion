#ifndef STOCKLION_PIECE_H
#define STOCKLION_PIECE_H

#include <vector>

enum Color {
    BLACK,
    WHITE
};

struct Position {
    char column;
    int row;
};


class Piece {
public:
    Position currentPosition;
    Color player;

    explicit Piece(Position initialPosition, Color player);
    virtual std::vector<Position> possibleMoves() = 0;
    void move(Position position);
};


#endif
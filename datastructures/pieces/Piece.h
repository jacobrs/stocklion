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

bool operator==(const Position &a, const Position &b) {
    return a.column == b.column && a.row == b.row;
}


class Piece {
public:
    Position currentPosition;
    Color player;

    explicit Piece(Position initialPosition, Color player);
    virtual std::vector<Position> possibleMoves() = 0;
    void move(Position position);
};


#endif

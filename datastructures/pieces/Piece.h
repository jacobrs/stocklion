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

    bool operator==(const Position &other);
};


class Piece {
public:
    Position currentPosition;
    Color player;

    explicit Piece(Position initialPosition, Color player);
    virtual ~Piece();
    virtual std::vector<Position> possibleMoves() = 0;
    virtual char getCLIToken() = 0;
    virtual char32_t getUnicodeToken() = 0;
    void move(Position position);
};


#endif

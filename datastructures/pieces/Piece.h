#ifndef STOCKLION_PIECE_H
#define STOCKLION_PIECE_H

#include <vector>

class Board;

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
    virtual std::vector<Position> possibleDirectMoves(Board& board) = 0;
    std::vector<Position> possibleMoves(Board& board);
    virtual char getCLIToken() = 0;
    void move(Position position);
};


#endif

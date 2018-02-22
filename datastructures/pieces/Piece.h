#ifndef STOCKLION_PIECE_H
#define STOCKLION_PIECE_H

#include <string>
#include <vector>

class Board;

enum Color {
    BLACK,
    WHITE
};

struct Position {
    char column;
    int row;

    bool operator==(const Position &other) const;
    bool operator!=(const Position &other) const;
};


class Piece {
public:
    Position currentPosition;
    Color player;

    bool isEnemyOrEmpty(Piece *p);
    explicit Piece(Position initialPosition, Color player);
    virtual ~Piece();
    virtual std::vector<Position> possibleDirectMoves(Board& board) = 0;
    std::vector<Position> possibleMoves(Board& board);
    virtual char getCLIToken() const = 0;
    virtual std::string getUnicodeToken() = 0;
    void move(Position position);
    bool operator==(const Piece &other) const;
    bool operator!=(const Piece &other) const;
};


#endif

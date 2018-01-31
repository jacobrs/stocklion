#ifndef STOCKLION_PIECES_H
#define STOCKLION_PIECES_H

#include <vector>
#include "Piece.h"

class Pawn : public Piece {
public:
    explicit Pawn(const Position &initialPosition, const Color &initialPlayer);
    std::vector<Position> possibleMoves();
};

class Knight : public Piece {
public:
    explicit Knight(const Position &initialPosition, const Color &initialPlayer);
    std::vector<Position> possibleMoves();
};

class Rook : public Piece {
public:
    explicit Rook(const Position &initialPosition, const Color &initialPlayer);
    std::vector<Position> possibleMoves();
};

class King : public Piece {
public:
    explicit King(const Position &initialPosition, const Color &initialPlayer);
    std::vector<Position> possibleMoves();
};

class Queen : public Piece {
public:
    explicit Queen(const Position &initialPosition, const Color &initialPlayer);
    std::vector<Position> possibleMoves();
};

class Bishop : public Piece {
public:
    explicit Bishop(const Position &initialPosition, const Color &initialPlayer);
    std::vector<Position> possibleMoves();
};


#endif

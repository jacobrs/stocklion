#ifndef STOCKLION_BISHOP_H
#define STOCKLION_BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
public:
    explicit Bishop(const Position &initialPosition, const Color &initialPlayer);
    std::vector<Position> possibleMoves() override;
};

#endif

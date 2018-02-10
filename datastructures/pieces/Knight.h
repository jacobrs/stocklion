#ifndef STOCKLION_KNIGHT_H
#define STOCKLION_KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
public:
    explicit Knight(const Position &initialPosition, const Color &initialPlayer);
    std::vector<Position> possibleMoves() override;
    char getCLIToken() override;
};


#endif

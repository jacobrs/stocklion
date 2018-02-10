#ifndef STOCKLION_KING_H
#define STOCKLION_KING_H

#include "Piece.h"

class King : public Piece {
public:
    explicit King(const Position &initialPosition, const Color &initialPlayer);
    std::vector<Position> possibleMoves() override;
    char getCLIToken() override;
};

#endif

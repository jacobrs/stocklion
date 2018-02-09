#ifndef STOCKLION_QUEEN_H
#define STOCKLION_QUEEN_H

#include "Piece.h"

class Queen : public Piece {
public:
    explicit Queen(const Position &initialPosition, const Color &initialPlayer);
    std::vector<Position> possibleMoves() override;
    char getCLIToken() override;
};

#endif

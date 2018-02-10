#ifndef STOCKLION_PIECES_H
#define STOCKLION_PIECES_H

#include <vector>
#include "Piece.h"

class Pawn : public Piece {
public:
    explicit Pawn(const Position &initialPosition, const Color &initialPlayer);
    std::vector<Position> possibleMoves() override;
    char getCLIToken() override;
};

#endif

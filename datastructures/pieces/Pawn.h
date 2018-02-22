#ifndef STOCKLION_PIECES_H
#define STOCKLION_PIECES_H

#include <vector>
#include "Piece.h"

class Pawn : public Piece {
public:
    explicit Pawn(const Position &initialPosition, const Color &initialPlayer);
    std::vector<Position> possibleDirectMoves(Board &board) override;
    char getCLIToken() const override;
    char32_t getUnicodeToken() override;
};

#endif

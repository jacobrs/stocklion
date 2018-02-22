#ifndef STOCKLION_ROOK_H
#define STOCKLION_ROOK_H

#include "Piece.h"

class Rook : public Piece {
public:
    explicit Rook(const Position &initialPosition, const Color &initialPlayer);
    std::vector<Position> possibleDirectMoves(Board &board) override;
    char getCLIToken() const override;
    std::string getUnicodeToken() override;
};

#endif

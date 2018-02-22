#ifndef STOCKLION_QUEEN_H
#define STOCKLION_QUEEN_H

#include "Piece.h"

class Queen : public Piece {
public:
    explicit Queen(const Position &initialPosition, const Color &initialPlayer);
    std::vector<Position> possibleDirectMoves(Board &board) override;
    char getCLIToken() const override;
    char32_t getUnicodeToken() override;
};

#endif

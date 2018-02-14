#ifndef STOCKLION_KNIGHT_H
#define STOCKLION_KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
public:
    explicit Knight(const Position &initialPosition, const Color &initialPlayer);
    std::vector<Position> possibleDirectMoves(Board &board) override;
    char getCLIToken() override;
    char32_t getUnicodeToken() override;
};


#endif

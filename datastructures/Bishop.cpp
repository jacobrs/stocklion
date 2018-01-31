#include "Bishop.h"

Bishop::Bishop(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}

std::vector<Position> Bishop::possibleMoves() {
    return std::vector<Position>();
}

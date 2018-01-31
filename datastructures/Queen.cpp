#include "Queen.h"

Queen::Queen(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}

std::vector<Position> Queen::possibleMoves() {
    return std::vector<Position>();
}

#include "Rook.h"

Rook::Rook(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}

std::vector<Position> Rook::possibleMoves() {
    return std::vector<Position>();
}

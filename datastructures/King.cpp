#include "King.h"

King::King(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}

std::vector<Position> King::possibleMoves() {
    return std::vector<Position>();
}

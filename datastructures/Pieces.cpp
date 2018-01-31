#include "Pieces.h"

Pawn::Pawn(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}
Rook::Rook(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}
Knight::Knight(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}
King::King(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}
Queen::Queen(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}
Bishop::Bishop(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}

std::vector<Position> Pawn::possibleMoves() {

}
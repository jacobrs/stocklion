#include "Piece.h"

void Piece::move(Position p) {
    currentPosition = p;
}

Piece::Piece(Position initialPosition, Color initialPlayer) {
    currentPosition = initialPosition;
    player = initialPlayer;
}

#include "Piece.h"

bool Position::operator==(const Position &a) {
    return column == a.column && row == a.row;
}

void Piece::move(Position p) {
    currentPosition = p;
}

Piece::Piece(Position initialPosition, Color initialPlayer) {
    currentPosition = initialPosition;
    player = initialPlayer;
}

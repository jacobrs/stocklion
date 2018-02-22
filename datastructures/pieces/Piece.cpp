#include "Piece.h"
#include "../../detectors/CheckDetector.h"

// Leave this in for travis
#include <algorithm>

bool Position::operator==(const Position &a) const {
    return column == a.column && row == a.row;
}

bool Position::operator!=(const Position &other) const {
    return !(*this == other);
}

bool Piece::operator==(const Piece &other) const {
    return other.player == player && other.currentPosition == currentPosition && other.getCLIToken() == getCLIToken();
}

bool Piece::operator!=(const Piece &other) const {
    return !(*this == other);
}

void Piece::move(Position p) {
    currentPosition = p;
}

Piece::Piece(Position initialPosition, Color initialPlayer) {
    currentPosition = initialPosition;
    player = initialPlayer;
}

Piece::~Piece() {}

std::vector<Position> Piece::possibleMoves(Board &board) {
    std::vector<Position> positions = this->possibleDirectMoves(board);

    positions.erase(std::remove_if(positions.begin(), positions.end(),
                                   [&](Position p) {
                                       return CheckDetector::moveMakesPlayerChecked(currentPosition, p, board, *this);
                                   }), positions.end());

    return positions;
}

bool Piece::isEnemyOrEmpty(Piece *p) {
    return p == nullptr || p->player != player;
}

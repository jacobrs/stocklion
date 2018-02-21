#include "Piece.h"
#include "../../detectors/CheckDetector.h"
#include <algorithm>

bool Position::operator==(const Position &a) {
    return column == a.column && row == a.row;
}

bool Position::operator!=(const Position &other) {
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

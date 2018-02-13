#include "Piece.h"
#include "../../detectors/CheckDetector.h"

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

Piece::~Piece() {}

std::vector<Position> Piece::possibleMoves(Board &board) {
    std::vector<Position> positions = this->possibleDirectMoves(board);

    positions.erase(std::remove_if(positions.begin(), positions.end(),
                                   [&](Position p) {
                                       return CheckDetector::moveMakesPlayerChecked(currentPosition, p, board, *this);
                                   }), positions.end());

    return positions;
}

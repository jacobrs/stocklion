#include "King.h"

King::King(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}

std::vector<Position> King::possibleMoves() {
    std::vector<Position> moves;
    Position possiblePositions;

    // Handles left side moves
    if (currentPosition.column - 1 >= 'A') {
        possiblePositions = {
                static_cast<char>(currentPosition.column - 1),
                currentPosition.row
        };
        moves.push_back(possiblePositions);

        if (currentPosition.row - 1 >= 1) {
            possiblePositions.row = currentPosition.row - 1;
            moves.push_back(possiblePositions);
        }

        if (currentPosition.row + 1 <= 8) {
            possiblePositions.row = currentPosition.row + 1;
            moves.push_back(possiblePositions);
        }
    }

    // Handles right side moves
    if (currentPosition.column + 1 <= 'H') {
        possiblePositions = {
                static_cast<char>(currentPosition.column + 1),
                currentPosition.row
        };
        moves.push_back(possiblePositions);

        if (currentPosition.row - 1 >= 1) {
            possiblePositions.row = currentPosition.row - 1;
            moves.push_back(possiblePositions);
        }

        if (currentPosition.row + 1 <= 8) {
            possiblePositions.row = currentPosition.row + 1;
            moves.push_back(possiblePositions);
        }
    }

    // Handles top middle
    if (currentPosition.row + 1 <= 8) {
        possiblePositions = {
                currentPosition.column,
                currentPosition.row + 1
        };
        moves.push_back(possiblePositions);
    }

    // Handle bottom middle
    if (currentPosition.row - 1 >= 1) {
        possiblePositions = {
                currentPosition.column,
                currentPosition.row - 1
        };
        moves.push_back(possiblePositions);
    }

    return moves;
}

#include "Knight.h"

Knight::Knight(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}

std::vector<Position> Knight::possibleMoves() {
    std::vector<Position> positions;
    Position possiblePositions;

    // Handle top positions
    if (currentPosition.row + 2 <= 8) {
        possiblePositions = {
                currentPosition.column,
                currentPosition.row + 2
        };

        if (currentPosition.column - 1 >= 'A') {
            possiblePositions.column = static_cast<char>(currentPosition.column - 1);
            positions.push_back(possiblePositions);
        }

        if (currentPosition.column + 1 <= 'H') {
            possiblePositions.column = static_cast<char>(currentPosition.column + 1);
            positions.push_back(possiblePositions);
        }
    }

    // Handle bottom positions
    if (currentPosition.row - 2 >= 1) {
        possiblePositions = {
                currentPosition.column,
                currentPosition.row - 2
        };

        if (currentPosition.column - 1 >= 'A') {
            possiblePositions.column = static_cast<char>(currentPosition.column - 1);
            positions.push_back(possiblePositions);
        }

        if (currentPosition.column + 1 <= 'H') {
            possiblePositions.column = static_cast<char>(currentPosition.column + 1);
            positions.push_back(possiblePositions);
        }
    }

    // Handle left positions
    if (currentPosition.column - 2 >= 'A') {
        possiblePositions = {
                static_cast<char>(currentPosition.column - 2),
                currentPosition.row
        };

        if (currentPosition.row - 1 >= 1) {
            possiblePositions.row = currentPosition.row - 1;
            positions.push_back(possiblePositions);
        }

        if (currentPosition.row + 1 <= 8) {
            possiblePositions.row = currentPosition.row + 1;
            positions.push_back(possiblePositions);
        }
    }

    // Handle right positions
    if (currentPosition.column + 2 <= 'H') {
        possiblePositions = {
                static_cast<char>(currentPosition.column + 2),
                currentPosition.row
        };

        if (currentPosition.row - 1 >= 1) {
            possiblePositions.row = currentPosition.row - 1;
            positions.push_back(possiblePositions);
        }

        if (currentPosition.row + 1 <= 8) {
            possiblePositions.row = currentPosition.row + 1;
            positions.push_back(possiblePositions);
        }
    }

    return positions;
}
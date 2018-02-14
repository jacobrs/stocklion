#include "Knight.h"

Knight::Knight(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}

std::vector<Position> Knight::possibleMoves() {
    std::vector<Position> positions;
    Position possiblePosition;

    possiblePosition = currentPosition;
    possiblePosition.row += 2;
    // Handle top positions
    if (possiblePosition.row <= 8) {
        if (possiblePosition.column - 1 >= 'A') {
            possiblePosition.column--;
            positions.push_back(possiblePosition);
            possiblePosition.column++;
        }

        if (possiblePosition.column + 1 <= 'H') {
            possiblePosition.column++;
            positions.push_back(possiblePosition);
        }
    }

    possiblePosition = currentPosition;
    possiblePosition.row -= 2;
    // Handle bottom positions
    if (possiblePosition.row >= 1) {
        if (possiblePosition.column - 1 >= 'A') {
            possiblePosition.column--;
            positions.push_back(possiblePosition);
            possiblePosition.column++;
        }

        if (possiblePosition.column + 1 <= 'H') {
            possiblePosition.column++;
            positions.push_back(possiblePosition);
        }
    }

    possiblePosition = currentPosition;
    possiblePosition.column -= 2;
    // Handle left positions
    if (possiblePosition.column >= 'A') {
        if (possiblePosition.row - 1 >= 1) {
            possiblePosition.row--;
            positions.push_back(possiblePosition);
            possiblePosition.row++;
        }

        if (possiblePosition.row + 1 <= 8) {
            possiblePosition.row++;
            positions.push_back(possiblePosition);
        }
    }

    possiblePosition = currentPosition;
    possiblePosition.column += 2;
    // Handle right positions
    if (possiblePosition.column <= 'H') {
        if (possiblePosition.row - 1 >= 1) {
            possiblePosition.row--;
            positions.push_back(possiblePosition);
            possiblePosition.row++;
        }

        if (possiblePosition.row + 1 <= 8) {
            possiblePosition.row++;
            positions.push_back(possiblePosition);
        }
    }

    return positions;
}

char Knight::getCLIToken() {
    return 'N';
}

char32_t Knight::getUnicodeToken() {
    if (player != WHITE) {
        return U'\u2658';
    } else {
        return U'\u265E';
    }
}
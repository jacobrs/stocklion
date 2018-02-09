#include "King.h"

King::King(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}

std::vector<Position> King::possibleMoves() {
    std::vector<Position> moves;
    Position possiblePosition;

    possiblePosition = currentPosition;
    possiblePosition.column--;
    // Handles left side moves
    if (possiblePosition.column >= 'A') {
        moves.push_back(possiblePosition);

        if (possiblePosition.row - 1 >= 1) {
            possiblePosition.row--;
            moves.push_back(possiblePosition);
            possiblePosition.row++;
        }

        if (possiblePosition.row + 1 <= 8) {
            possiblePosition.row++;
            moves.push_back(possiblePosition);
        }
    }

    possiblePosition = currentPosition;
    possiblePosition.column++;
    // Handles right side moves
    if (possiblePosition.column <= 'H') {
        moves.push_back(possiblePosition);

        if (possiblePosition.row - 1 >= 1) {
            possiblePosition.row--;
            moves.push_back(possiblePosition);
            possiblePosition.row++;
        }

        if (possiblePosition.row + 1 <= 8) {
            possiblePosition.row++;
            moves.push_back(possiblePosition);
        }
    }

    possiblePosition = currentPosition;
    possiblePosition.row++;
    // Handles top middle
    if (possiblePosition.row <= 8) {
        moves.push_back(possiblePosition);
    }

    possiblePosition = currentPosition;
    possiblePosition.row--;
    // Handle bottom middle
    if (possiblePosition.row >= 1) {
        moves.push_back(possiblePosition);
    }

    return moves;
}

char King::getCLIToken() {
    return 'K';
}
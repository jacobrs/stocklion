#include "King.h"
#include "../../detectors/CheckDetector.h"

King::King(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}

std::vector<Position> King::possibleDirectMoves(Board &board) {
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

char32_t King::getUnicodeToken() {
    if (player != WHITE) {
        return U'\u2654';
    } else {
        return U'\u265A';
    }
}
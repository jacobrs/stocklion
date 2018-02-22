#include "King.h"
#include "../../detectors/CheckDetector.h"

King::King(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}

std::vector<Position> King::possibleDirectMoves(Board &board) {
    std::vector<Position> moves;

    Position possiblePosition = currentPosition;
    possiblePosition.column--;
    // Handles left side moves
    if (possiblePosition.column >= 'A') {
        if(this->isEnemyOrEmpty(board.getPiece(possiblePosition))) {
            moves.push_back(possiblePosition);
        }

        if (possiblePosition.row - 1 >= 1) {
            possiblePosition.row--;
            if(this->isEnemyOrEmpty(board.getPiece(possiblePosition))) {
                moves.push_back(possiblePosition);
            }
            possiblePosition.row++;
        }

        if (possiblePosition.row + 1 <= 8) {
            possiblePosition.row++;
            if(this->isEnemyOrEmpty(board.getPiece(possiblePosition))) {
                moves.push_back(possiblePosition);
            }
        }
    }

    possiblePosition = currentPosition;
    possiblePosition.column++;
    // Handles right side moves
    if (possiblePosition.column <= 'H') {
        if(this->isEnemyOrEmpty(board.getPiece(possiblePosition))) {
            moves.push_back(possiblePosition);
        }

        if (possiblePosition.row - 1 >= 1) {
            possiblePosition.row--;
            if(this->isEnemyOrEmpty(board.getPiece(possiblePosition))) {
                moves.push_back(possiblePosition);
            }
            possiblePosition.row++;
        }

        if (possiblePosition.row + 1 <= 8) {
            possiblePosition.row++;
            if(this->isEnemyOrEmpty(board.getPiece(possiblePosition))) {
                moves.push_back(possiblePosition);
            }
        }
    }

    possiblePosition = currentPosition;
    possiblePosition.row++;
    // Handles top middle
    if (possiblePosition.row <= 8) {
        if(this->isEnemyOrEmpty(board.getPiece(possiblePosition))) {
            moves.push_back(possiblePosition);
        }
    }

    possiblePosition = currentPosition;
    possiblePosition.row--;
    // Handle bottom middle
    if (possiblePosition.row >= 1) {
        if(this->isEnemyOrEmpty(board.getPiece(possiblePosition))) {
            moves.push_back(possiblePosition);
        }
    }

    return moves;
}

char King::getCLIToken() const {
    return 'K';
}

std::string King::getUnicodeToken() {
    if (player != WHITE) {
        return "\u2654";
    }
    return "\u265A";
}
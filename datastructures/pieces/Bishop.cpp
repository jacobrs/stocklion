#include "Bishop.h"

Bishop::Bishop(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}

std::vector<Position> Bishop::possibleMoves() {

    std::vector<Position> positions;

    // top left to bottom right
    Position comparison = currentPosition;
    while(comparison.row < 8 && comparison.column > 'A'){
        comparison.row ++;
        comparison.column --;
    }

    while(comparison.row >= 1 && comparison.column <= 'H'){
        if(comparison.row != currentPosition.row && comparison.column != currentPosition.column) {
            positions.push_back(comparison);
        }
        comparison.row--;
        comparison.column++;
    }

    // bottom left to top right
    comparison = currentPosition;
    while(comparison.row > 1 && comparison.column > 'A'){
        comparison.row --;
        comparison.column --;
    }

    while(comparison.row <= 8 && comparison.column <= 'H'){
        if(comparison.row != currentPosition.row && comparison.column != currentPosition.column) {
            positions.push_back(comparison);
        }
        comparison.row ++;
        comparison.column ++;
    }

    return positions;
}

char Bishop::getCLIToken() {
    return 'B';
}

char32_t Bishop::getUnicodeToken() {
    if (player != WHITE) {
        return U'\u2657';
    } else {
        return U'\u265D';
    }
}
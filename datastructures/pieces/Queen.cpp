#include "Queen.h"

Queen::Queen(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}

std::vector<Position> Queen::possibleDirectMoves(Board &board) {
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

    for(char i = 'A'; i <= 'H'; i++){
        if(i != currentPosition.column){
            positions.push_back({ i, currentPosition.row });
        }
    }

    for(int i = 1; i <= 8; i++){
        if(i != currentPosition.row){
            positions.push_back( { currentPosition.column, i });
        }
    }

    return positions;
}

char Queen::getCLIToken() {
    return 'Q';
}

char32_t Queen::getUnicodeToken() {
    if (player != WHITE) {
        return U'\u2655';
    } else {
        return U'\u265B';
    }
}

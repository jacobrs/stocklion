#include "Rook.h"

Rook::Rook(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}

std::vector<Position> Rook::possibleDirectMoves(Board &board) {
    std::vector<Position> positions;

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

char Rook::getCLIToken() {
    return 'R';
}

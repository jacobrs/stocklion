#include "Pawn.h"

Pawn::Pawn(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}

bool canJumpTwoSpaces(const Pawn &p){
    return (p.currentPosition.row == 6 && p.player == BLACK) || (p.player == WHITE && p.currentPosition.row == 2);
}

std::vector<Position> Pawn::possibleMoves() {
    int max_jump = canJumpTwoSpaces(*this) ? 2 : 1;
    std::vector<Position> positions;

    // compute available moves
    for(int i = 1; i <= max_jump; i++) {
        Position newPosition = currentPosition;
        if(player == BLACK) {
            newPosition.row -= i;
        }
        else {
            newPosition.row += i;
        }
        if(newPosition.row <= 8 && newPosition.row >= 1) {
            positions.push_back(newPosition);
        }
    }

    // compute capture moves
    Position leftCapture = currentPosition;
    Position rightCapture = currentPosition;

    if(player == BLACK) {
        leftCapture.row --;
        rightCapture.row --;
    } else {
        leftCapture.row ++;
        rightCapture.row ++;
    }

    leftCapture.column --;
    rightCapture.column ++;

    if(leftCapture.row >= 1 && leftCapture.row <= 8){
        if(leftCapture.column >= 'A') {
            positions.push_back(leftCapture);
        }
        if(rightCapture.column <= 'H') {
            positions.push_back(rightCapture);
        }
    }

    return positions;
}

char Pawn::getCLIToken() {
    return 'P';
}
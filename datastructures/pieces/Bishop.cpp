#include "Bishop.h"
#include "../../detectors/CheckDetector.h"

Bishop::Bishop(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}

std::vector<Position> Bishop::possibleDirectMoves(Board& board) {

    std::vector<Position> positions;

    // top left to bottom right
    Position comparison = currentPosition;
    Piece *potentialPiece;
    while(comparison.row < 8 && comparison.column > 'A'){
        comparison.row ++;
        comparison.column --;
        potentialPiece = board.getPiece(comparison);
        if(potentialPiece != nullptr && potentialPiece != this){
            break;
        }
    }

    while(comparison.row >= 1 && comparison.column <= 'H'){
        potentialPiece = board.getPiece(comparison);
        if(potentialPiece != nullptr && potentialPiece->player == player){
            comparison.row--;
            comparison.column++;
            continue;
        }
        if(comparison.row != currentPosition.row && comparison.column != currentPosition.column) {
            positions.push_back(comparison);
        }
        comparison.row--;
        comparison.column++;
        potentialPiece = board.getPiece(comparison);
        if(potentialPiece != nullptr && potentialPiece != this){
            if(potentialPiece->player != player){
                positions.push_back(comparison);
            }
            break;
        }
    }

    // bottom left to top right
    comparison = currentPosition;
    while(comparison.row > 1 && comparison.column > 'A'){
        comparison.row --;
        comparison.column --;
        potentialPiece = board.getPiece(comparison);
        if(potentialPiece != nullptr && potentialPiece != this){
            break;
        }
    }

    while(comparison.row <= 8 && comparison.column <= 'H'){
        potentialPiece = board.getPiece(comparison);
        if(potentialPiece != nullptr && potentialPiece->player == player){
            comparison.row ++;
            comparison.column ++;
            continue;
        }
        if(comparison.row != currentPosition.row && comparison.column != currentPosition.column) {
            positions.push_back(comparison);
        }
        comparison.row ++;
        comparison.column ++;
        potentialPiece = board.getPiece(comparison);
        if(potentialPiece != nullptr && potentialPiece != this){
            if(potentialPiece->player != player){
                positions.push_back(comparison);
            }
            break;
        }
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
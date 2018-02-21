#include "Bishop.h"
#include "../../detectors/CheckDetector.h"

Bishop::Bishop(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}

std::vector<Position> Bishop::possibleDirectMoves(Board& board) {

    std::vector<Position> positions;

    // to top left
    Position comparison = currentPosition;
    Piece *potentialPiece;
    comparison.row++;
    comparison.column--;
    while(comparison.row <= 8 && comparison.column >= 'A') {
        potentialPiece = board.getPiece(comparison);
        if(potentialPiece != nullptr){
            if(potentialPiece->player != player){
                positions.push_back(comparison);
            }
            break;
        }else{
            positions.push_back(comparison);
            comparison.row++;
            comparison.column--;
        }
    }

    // to bottom right
    comparison = currentPosition;
    comparison.row--;
    comparison.column++;
    while(comparison.row >= 1 && comparison.column <= 'H') {
        potentialPiece = board.getPiece(comparison);
        if(potentialPiece != nullptr){
            if(potentialPiece->player != player){
                positions.push_back(comparison);
            }
            break;
        }else{
            positions.push_back(comparison);
            comparison.row--;
            comparison.column++;
        }
    }

    // to bottom left
    comparison = currentPosition;
    comparison.row--;
    comparison.column--;
    while(comparison.row >= 1 && comparison.column >= 'A') {
        potentialPiece = board.getPiece(comparison);
        if(potentialPiece != nullptr){
            if(potentialPiece->player != player){
                positions.push_back(comparison);
            }
            break;
        }else{
            positions.push_back(comparison);
            comparison.row--;
            comparison.column--;
        }
    }

    // to top right
    comparison = currentPosition;
    comparison.row++;
    comparison.column++;
    while(comparison.row <= 8 && comparison.column <= 'H') {
        potentialPiece = board.getPiece(comparison);
        if(potentialPiece != nullptr){
            if(potentialPiece->player != player){
                positions.push_back(comparison);
            }
            break;
        }else{
            positions.push_back(comparison);
            comparison.row++;
            comparison.column++;
        }
    }

    return positions;
}

char Bishop::getCLIToken() const {
    return 'B';
}

char32_t Bishop::getUnicodeToken() {
    if (player != WHITE) {
        return U'\u2657';
    } else {
        return U'\u265D';
    }
}
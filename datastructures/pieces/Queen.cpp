#include "Queen.h"
#include "../Board.h"

Queen::Queen(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}

std::vector<Position> Queen::possibleDirectMoves(Board &board) {
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

    for(char i = currentPosition.column; i <= 'H'; i++){
        if(i != currentPosition.column){
            potentialPiece = board.getPiece({i, currentPosition.row});
            if(potentialPiece != nullptr && potentialPiece != this){
                // other piece
                if(potentialPiece->player != player){
                    positions.push_back({ i, currentPosition.row });
                }
                break;
            }else {
                positions.push_back({i, currentPosition.row});
            }
        }
    }

    for(char i = currentPosition.column; i >= 'A'; i--){
        if(i != currentPosition.column){
            potentialPiece = board.getPiece({i, currentPosition.row});
            if(potentialPiece != nullptr && potentialPiece != this){
                // other piece
                if(potentialPiece->player != player){
                    positions.push_back({ i, currentPosition.row });
                }
                break;
            }else {
                positions.push_back({i, currentPosition.row});
            }
        }
    }

    for(int i = currentPosition.row; i <= 8; i++){
        if(i != currentPosition.row){
            potentialPiece = board.getPiece({ currentPosition.column, i });
            if(potentialPiece != nullptr && potentialPiece != this){
                // other piece
                if(potentialPiece->player != player){
                    positions.push_back({ currentPosition.column, i });
                }
                break;
            }else {
                positions.push_back({currentPosition.column, i});
            }
        }
    }

    for(int i = currentPosition.row; i >= 1; i--){
        if(i != currentPosition.row){
            potentialPiece = board.getPiece({ currentPosition.column, i });
            if(potentialPiece != nullptr && potentialPiece != this){
                // other piece
                if(potentialPiece->player != player){
                    positions.push_back({ currentPosition.column, i });
                }
                break;
            }else {
                positions.push_back({currentPosition.column, i});
            }
        }
    }

    return positions;
}

char Queen::getCLIToken() const {
    return 'Q';
}

std::string Queen::getUnicodeToken() {
    if (player != WHITE) {
        return "\u2655";
    }
    return "\u265B";
}

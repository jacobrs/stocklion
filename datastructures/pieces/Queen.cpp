#include "Queen.h"
#include "../Board.h"

Queen::Queen(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}

std::vector<Position> Queen::possibleDirectMoves(Board &board) {
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
        if(potentialPiece != nullptr && potentialPiece->player == player && potentialPiece != this){
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
        if(potentialPiece != nullptr && potentialPiece->player == player && potentialPiece != this){
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

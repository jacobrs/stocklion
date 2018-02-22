#include "Rook.h"
#include "../Board.h"

Rook::Rook(const Position &initialPosition, const Color &initialPlayer) : Piece(initialPosition, initialPlayer) {}

std::vector<Position> Rook::possibleDirectMoves(Board &board) {
    std::vector<Position> positions;
    Piece *potentialPiece;

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

char Rook::getCLIToken() const {
    return 'R';
}

std::string Rook::getUnicodeToken() {
    if (player != WHITE) {
        return "\u2656";
    } else {
        return "\u265C";
    }
}
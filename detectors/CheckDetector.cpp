#include "CheckDetector.h"

bool CheckDetector::playerInCheck(Color player, Board& board) {

    std::vector<Piece*> enemyPieces;
    Piece *attackedKind = nullptr;

    for(int i = 1; i < 9; i ++){
        for(char j = 'A'; j < 'I'; j++){
            Piece *p = board.getPiece({ j, i });
            if(p != nullptr && p->player != player) {
                enemyPieces.push_back(p);
            }
            if(p != nullptr && p->getCLIToken() == 'K' && p->player == player){
                attackedKind = p;
            }
        }
    }

    bool res = false;

    if(attackedKind != nullptr) {
        for (auto p : enemyPieces) {
            for (auto attack : p->possibleDirectMoves(board)) {
                if (attack == attackedKind->currentPosition) {
                    res = true;
                    break;
                }
            }
            if (res) {
                break;
            }
        }
    }

    return res;
}

bool CheckDetector::moveMakesPlayerChecked(Position initial, Position target, Board &board, Piece &p) {
    return false;
}

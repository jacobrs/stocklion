#ifndef STOCKLION_CHECKDETECTOR_H
#define STOCKLION_CHECKDETECTOR_H


#include "../datastructures/pieces/Piece.h"
#include "../datastructures/Board.h"

class CheckDetector {

public:
    static bool playerInCheck(Color player, Board& board);

};


#endif

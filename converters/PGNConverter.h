#ifndef STOCKLION_PGNCONVERTER_H
#define STOCKLION_PGNCONVERTER_H

#include <string>
#include "../datastructures/Board.h"

enum MoveType {
    PIECE_MOVE,
    PAWN_MOVE,
    CASTLE_MOVE_KING,
    CASTLE_MOVE_QUEEN,
    RESULT_MOVE,
    INVALID_MOVE
};

class PGNConverter {
private:
    static void getPieceOrPawnPosition(Color, std::string, Board*, Position&, Position&);
    static Board *emptyBoard;
public:
    static void convert(std::string, Board*);
    static void playAlgebraicMove(Color, std::string, Board *);
    static int getAlgebraicMoveType(std::string);
};

#endif //STOCKLION_PGNCONVERTER_H

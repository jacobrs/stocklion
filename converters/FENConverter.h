#ifndef STOCKLION_FENCONVERTER_H
#define STOCKLION_FENCONVERTER_H

#include <string>
#include "../datastructures/Board.h"

class FENConverter {

public:
    void convert(std::string fen, Board *board);
};


#endif

#ifndef STOCKLION_PGNCONVERTER_H
#define STOCKLION_PGNCONVERTER_H

#include "../datastructures/Board.h"

class PGNConverter {
private:

public:
    PGNConverter();
    void convert(std::string, Board*);
};

#endif //STOCKLION_PGNCONVERTER_H

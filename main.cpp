#include <iostream>
#include "datastructures/Pieces.h"


int main() {

    Position initialPosition = { 'E', 2 };
    Pawn *p = new Pawn(initialPosition, WHITE);

    for(auto position: p->possibleMoves()){
        std::cout << position.column << position.row << " ";
    }

    return 0;
}
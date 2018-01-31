#include <iostream>
#include "datastructures/Pawn.h"
#include "datastructures/King.h"
#include "datastructures/Knight.h"


int main() {

    Position initialPosition = { 'D', 1 };
    Knight *p = new Knight(initialPosition, WHITE);

    for(auto position: p->possibleMoves()){
        std::cout << position.column << position.row << " ";
    }

    return 0;
}
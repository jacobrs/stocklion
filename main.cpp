#include <iostream>
#include "datastructures/Pawn.h"
#include "datastructures/Bishop.h"
#include "datastructures/Rook.h"


int main() {

    Position initialPosition = { 'E', 2 };
    Pawn *p = new Pawn(initialPosition, WHITE);
    Bishop *bishop = new Bishop({ 'E', 4 }, WHITE);
    Rook *rook = new Rook({ 'E', 4 }, BLACK);

    for(auto position: p->possibleMoves()){
        std::cout << position.column << position.row << " ";
    }

    std::cout << std::endl;

    for(auto position: bishop->possibleMoves()){
        std::cout << position.column << position.row << " ";
    }

    std::cout << std::endl;

    for(auto position: rook->possibleMoves()){
        std::cout << position.column << position.row << " ";
    }

    return 0;
}
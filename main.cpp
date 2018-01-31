#include <iostream>
#include "datastructures/Pawn.h"
#include "datastructures/Bishop.h"
#include "datastructures/Rook.h"
#include "datastructures/Queen.h"
#include "datastructures/King.h"
#include "datastructures/Knight.h"

int main() {

    Position initialPosition = { 'E', 2 };
    Pawn *p = new Pawn(initialPosition, WHITE);
    Bishop *bishop = new Bishop({ 'E', 4 }, WHITE);
    Rook *rook = new Rook({ 'E', 4 }, BLACK);
    Queen *queen = new Queen({ 'E', 4}, BLACK);
    King *king = new King({ 'E', 4}, WHITE);
    Knight *knight = new Knight({ 'E', 4}, WHITE);

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

    std::cout << std::endl;

    for(auto position: queen->possibleMoves()){
        std::cout << position.column << position.row << " ";
    }

    std::cout << std::endl;

    for(auto position: king->possibleMoves()){
        std::cout << position.column << position.row << " ";
    }

    std::cout << std::endl;

    for(auto position: knight->possibleMoves()){
        std::cout << position.column << position.row << " ";
    }

    return 0;
}

#include <iostream>
#include "datastructures/pieces/Pawn.h"
#include "datastructures/pieces/Bishop.h"
#include "datastructures/pieces/Rook.h"
#include "datastructures/pieces/Queen.h"
#include "datastructures/pieces/King.h"
#include "datastructures/pieces/Knight.h"
#include "converters/FENConverter.h"
#include "converters/PGNConverter.h"

int main() {

    Board *board = new Board(WHITE);
    Position initialPosition = { 'E', 2 };
    Pawn *p = new Pawn(initialPosition, WHITE);
    Bishop *bishop = new Bishop({ 'E', 4 }, WHITE);
    Rook *rook = new Rook({ 'E', 4 }, BLACK);
    Queen *queen = new Queen({ 'E', 4}, BLACK);
    King *king = new King({ 'E', 4}, WHITE);
    Knight *knight = new Knight({ 'E', 4}, WHITE);

    for(auto position: p->possibleMoves(*board)){
        std::cout << position.column << position.row << " ";
    }

    std::cout << std::endl;

    for(auto position: bishop->possibleMoves(*board)){
        std::cout << position.column << position.row << " ";
    }

    std::cout << std::endl;

    for(auto position: rook->possibleMoves(*board)){
        std::cout << position.column << position.row << " ";
    }

    std::cout << std::endl;

    for(auto position: queen->possibleMoves(*board)){
        std::cout << position.column << position.row << " ";
    }

    std::cout << std::endl;

    for(auto position: king->possibleMoves(*board)){
        std::cout << position.column << position.row << " ";
    }

    std::cout << std::endl;

    for(auto position: knight->possibleMoves(*board)){
        std::cout << position.column << position.row << " ";
    }

    Board *fenBoard = new Board(WHITE);
    FENConverter::convert("rnbqk2r/pppp1ppp/4pn2/1B1P4/1b6/4P3/PPP2PPP/RNBQK1NR w KQkq -", fenBoard);

    std::cout << std::endl << "loaded from fen successfully" << std::endl;
    fenBoard->printBoard();

    Board *pgnBoardFirst = new Board(WHITE);
    PGNConverter::convert("1. d4 e5 2. dxe5 Qf6 3. Kd2 Qxe5 4. Nf3 Qe3+\n"
                          "5. Ke1 Qxc1 6. Nc3 Qf4 7. Nd4 f5 8. Nxf5\n", pgnBoardFirst);

    std::cout << std::endl << "loaded from PGN successfully" << std::endl;
    pgnBoardFirst->printBoard();

    Board *pgnBoardSecond = new Board(WHITE);
    PGNConverter::convert("1. d4 e5 2. dxe5 Qf6 3. Kd2 Qxe5 4. Nf3 Qe3+\n"
                          "5. Ke1 Qxc1 6. Nc3 Qf4 7. Nd4 f5 8. Nxf5 Qxf5\n", pgnBoardSecond);

    std::cout << std::endl << "loaded from PGN successfully" << std::endl;
    pgnBoardSecond->printUnicodeBoard();

    return 0;
}

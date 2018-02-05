#include <iostream>
#include "Board.h"
#include "pieces/Bishop.h"
#include "pieces/King.h"
#include "pieces/Knight.h"
#include "pieces/Pawn.h"
#include "pieces/Queen.h"
#include "pieces/Rook.h"


Board::Board(Color &playerColor) {
    this->playerColor = playerColor;
    initState();
}

bool Board::movePiece(Position &initPos, Position &destPos, Color player) {
    if (!isMoveValid(initPos, destPos, player))
        return false;
    else {
        board[destPos.row][destPos.column - 'A' + 1] = board[initPos.row][initPos.column - 'A' + 1];
        board[initPos.row][initPos.column - 'A' + 1] = nullptr;
        return true;
    }
}

bool Board::isMoveValid(Position &initPos, Position &destPos, Color player) {
    auto piece = board[initPos.row][initPos.column - 'A' + 1];

    if (piece == nullptr) {
        std::cout << "POSITION ERROR attempted to get a position that has no piece" << std::endl;
        return false;
    }

    if (piece->player != player)
        return false;

    //TODO pass the board to the function
    std::vector<Position> possibleMoves = piece->possibleMoves();
    bool canBeDone = false;
    for (auto &&position : possibleMoves) {
        if (position == initPos)
            canBeDone = true;
    }

    return canBeDone;

    //TODO Check to see if there's a check!
}

std::vector<Position> Board::validMovesOfPiece(Position &piecePos) {
    return board[piecePos.row][piecePos.column - 'A' + 1]->possibleMoves();
}

Color *Board::whoWon() {
    //TODO
    return nullptr;
}


void Board::initState() {
    //Black and white Pawn initialization
    for (int i = 1; i <= 8; ++i) {
        board[2][i] = new Pawn(*(new Position({(char)('A' + i - 1), 2})), WHITE);
        board[7][i] = new Pawn(*(new Position({(char)('A' + i - 1), 7})), BLACK);
    }

    //Rook initialization
    board[1][1] = new Rook(*(new Position({'A', 1})), WHITE);
    board[1][8] = new Rook(*(new Position({'H', 1})), WHITE);
    board[8][1] = new Rook(*(new Position({'A', 8})), BLACK);
    board[8][8] = new Rook(*(new Position({'H', 8})), BLACK);

    //Knight initialization
    board[1][2] = new Knight(*(new Position({'B', 1})), WHITE);
    board[1][7] = new Knight(*(new Position({'G', 1})), WHITE);
    board[8][2] = new Knight(*(new Position({'B', 8})), BLACK);
    board[8][7] = new Knight(*(new Position({'G', 8})), BLACK);

    //Bishop initialization
    board[1][3] = new Bishop(*(new Position({'C', 1})), WHITE);
    board[1][6] = new Bishop(*(new Position({'F', 1})), WHITE);
    board[8][3] = new Bishop(*(new Position({'C', 8})), BLACK);
    board[8][6] = new Bishop(*(new Position({'F', 8})), BLACK);

    //Queen initialization
    board[1][4] = new Queen(*(new Position({'D', 1})), WHITE);
    board[8][4] = new Queen(*(new Position({'D', 8})), BLACK);

    //King initialization
    board[1][5] = new King(*(new Position({'E', 1})), WHITE);
    board[8][5] = new King(*(new Position({'E', 8})), BLACK);
}



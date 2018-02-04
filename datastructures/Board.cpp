//
// Created by Yashar Dabiran on 2018-02-03.
//

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

    if (piece->player != player)
        return false;

    //TODO pass the board to the function
    std::vector<Position> possibleMoves = piece->possibleMoves();
    bool canBeDone = false;
    for (auto &&position : possibleMoves) {
        if (position.row == initPos.row && position.column == initPos.column)
            canBeDone = true;
    }
    if (!canBeDone)
        return false;

    //TODO Check to see if there's a check!
    return true;
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
        auto *pos = new Position;
        pos->column = (char)('A' + i - 1);
        pos->row = 2;
        board[2][i] = new Pawn(*pos, WHITE);

        pos = new Position;
        pos->column = (char)('A' + i - 1);
        pos->row = 7;
        board[7][i] = new Pawn(*pos, BLACK);
    }

    //Rook initialization
    auto *pos = new Position;
    pos->row = 1;
    pos->column = 'A';
    board[1][1] = new Rook(*pos, WHITE);

    pos = new Position;
    pos->row = 1;
    pos->column = 'H';
    board[1][8] = new Rook(*pos, WHITE);

    pos = new Position;
    pos->row = 8;
    pos->column = 'A';
    board[8][1] = new Rook(*pos, BLACK);

    pos = new Position;
    pos->row = 8;
    pos->column = 'H';
    board[8][8] = new Rook(*pos, BLACK);


    //Knight initialization
    pos = new Position;
    pos->row = 1;
    pos->column = 'B';
    board[1][2] = new Knight(*pos, WHITE);

    pos = new Position;
    pos->row = 1;
    pos->column = 'G';
    board[1][7] = new Knight(*pos, WHITE);

    pos = new Position;
    pos->row = 8;
    pos->column = 'B';
    board[8][2] = new Knight(*pos, BLACK);

    pos = new Position;
    pos->row = 8;
    pos->column = 'G';
    board[8][7] = new Knight(*pos, BLACK);

    //Bishop initialization
    pos = new Position;
    pos->row = 1;
    pos->column = 'C';
    board[1][3] = new Bishop(*pos, WHITE);

    pos = new Position;
    pos->row = 1;
    pos->column = 'F';
    board[1][6] = new Bishop(*pos, WHITE);

    pos = new Position;
    pos->row = 8;
    pos->column = 'C';
    board[8][3] = new Bishop(*pos, BLACK);

    pos = new Position;
    pos->row = 8;
    pos->column = 'F';
    board[8][6] = new Bishop(*pos, BLACK);

    //Queen initialization
    pos = new Position;
    pos->row = 1;
    pos->column = 'D';
    board[1][4] = new Queen(*pos, WHITE);

    pos = new Position;
    pos->row = 8;
    pos->column = 'D';
    board[8][4] = new Queen(*pos, BLACK);

    //King initialization
    pos = new Position;
    pos->row = 1;
    pos->column = 'E';
    board[1][5] = new King(*pos, WHITE);

    pos = new Position;
    pos->row = 8;
    pos->column = 'E';
    board[8][5] = new King(*pos, BLACK);
}



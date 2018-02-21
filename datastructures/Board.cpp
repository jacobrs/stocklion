#include <iostream>
#include "Board.h"
#include "pieces/Bishop.h"
#include "pieces/King.h"
#include "pieces/Knight.h"
#include "pieces/Pawn.h"
#include "pieces/Queen.h"
#include "pieces/Rook.h"
#include "../util/UnicodeTable.h"

Board::Board() {
    playerColor = WHITE;
    initState();
}

Board::Board(Color playerColor) {
    this->playerColor = playerColor;
    initState();
}

bool Board::movePiece(Position &initPos, Position &destinationPosition, Color player) {
    if (!isMoveValid(initPos, destinationPosition, player))
        return false;
    else {
        getPiece(initPos)->move(destinationPosition);
        board[destinationPosition.row][destinationPosition.column - 'A' + 1] = board[initPos.row][initPos.column - 'A' + 1];
        board[initPos.row][initPos.column - 'A' + 1] = nullptr;
        return true;
    }
}

bool Board::isMoveValid(Position &initPos, Position &destinationPosition, Color player) {
    auto piece = board[initPos.row][initPos.column - 'A' + 1];

    if (piece == nullptr) {
        std::cout << "POSITION ERROR attempted to get a position that has no piece" << std::endl;
        return false;
    }

    if (piece->player != player)
        return false;

    std::vector<Position> possibleMoves = piece->possibleMoves(*this);
    bool canBeDone = false;
    for (auto &&position : possibleMoves) {
        if (position == destinationPosition) {
            canBeDone = true;
            break;
        }
    }

    if(!canBeDone){
        return false;
    }

    return true;
}

std::vector<Position> Board::validMovesOfPiece(Position &piecePos) {
    return board[piecePos.row][piecePos.column - 'A' + 1]->possibleMoves(*this);
}

void Board::initState() {
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            board[i][j] = nullptr;

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

void Board::placePiece(Position pos, Piece *p) {
    int row = pos.row;
    int col = pos.column - 'A' + 1;
    board[row][col] = p;
}

void Board::setPlayerColor(Color c) {
    this->playerColor = c;
}

void Board::wipeBoard() {
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] != nullptr)
                delete board[i][j];
            board[i][j] = nullptr;
        }
    }
}

void Board::printBoard() {
    for (int i = 8; i >= 0; i--) {
        std::cout << i << " ";
        for (int j = 1; j < 9; j++) {
            if(i == 0)
                std::cout << (char)('A' + j - 1) << " ";
            else {
                char token = ' ';
                if(board[i][j] != nullptr){
                    token = board[i][j]->getCLIToken();
                    if(board[i][j]->player == BLACK){
                        token = (char)(tolower(token));
                    }
                }

                std::cout << token << " ";
            }
        }
        std::cout << std::endl;
    }
}

void Board::printUnicodeBoard() {
    std::cout << " ";
    UnicodeTable::printLine(TOP, 9);
    std::cout << std::endl;
    for (int i = 8; i >= 0; i--) {
        std::cout << i;
        if (i != 0) {
            UnicodeTable::printChar("VERTICAL_LINE");
        } else {
            std::cout << "  ";
        }

        for (int j = 1; j < 9; j++) {
            if(i == 0)
                std::cout << (char)('A' + j - 1) << "   ";
            else {
                char32_t token = ' ';
                if(board[i][j] != nullptr){
                    token = board[i][j]->getUnicodeToken();
                }
                std::cout << " ";
                UnicodeTable::printChar32(token);
                std::cout << " ";
                UnicodeTable::printChar("VERTICAL_LINE");
            }
        }

        if (i == 1) {
            std::cout << std::endl << " ";
            UnicodeTable::printLine(BOTTOM, 9);
        } else if (i != 0) {
            std::cout << std::endl << " ";
            UnicodeTable::printLine(MIDDLE, 9);
        }
        std::cout << std::endl;
    }
}

Piece* Board::getPiece(Position position) {
    return board[position.row][(int)(position.column - 'A') + 1];
}

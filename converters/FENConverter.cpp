#include <iostream>
#include "FENConverter.h"
#include "../datastructures/pieces/Rook.h"
#include "../datastructures/pieces/Bishop.h"
#include "../datastructures/pieces/King.h"
#include "../datastructures/pieces/Queen.h"
#include "../datastructures/pieces/Knight.h"
#include "../datastructures/pieces/Pawn.h"

void FENConverter::convert(std::string fen, Board *board) {

    board->wipeBoard();

    int row = 8;
    char col = 'A';

    try {

        for (int i = 0; i < fen.length(); i++) {
            if (col > 'H') {
                col = 'A';
                row--;
            }
            char c = fen[i];
            if (c >= '1' && c <= '8') {
                col += c - '0';
                continue;
            }
            if (c == ' ') {
                Color color = (fen[i + 1] == 'b') ? BLACK : WHITE;
                board->setPlayerColor(color);
                break;
            }
            if ( c == '/' ) {
                continue;
            }

            Position p = {col, row};

            switch (c) {
                case ('r'):
                case ('R'):
                    board->placePiece(p, new Rook(p, (c == 'r') ? BLACK : WHITE));
                    break;
                case ('b'):
                case ('B'):
                    board->placePiece(p, new Bishop(p, (c == 'b') ? BLACK : WHITE));
                    break;
                case ('k'):
                case ('K'):
                    board->placePiece(p, new King(p, (c == 'k') ? BLACK : WHITE));
                    break;
                case ('n'):
                case ('N'):
                    board->placePiece(p, new Knight(p, (c == 'n') ? BLACK : WHITE));
                    break;
                case ('q'):
                case ('Q'):
                    board->placePiece(p, new Queen(p, (c == 'q') ? BLACK : WHITE));
                    break;
                case ('p'):
                case ('P'):
                    board->placePiece(p, new Pawn(p, (c == 'p') ? BLACK : WHITE));
                    break;
                default:
                    throw std::exception();
            }
            col++;
        }

    } catch (std::exception& e){
        std::cout << "Error converting board from FEN " << fen << std::endl;
    }
}

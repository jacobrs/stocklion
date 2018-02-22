#include <regex>
#include "PGNConverter.h"
#include "../datastructures/pieces/King.h"
#include "../datastructures/pieces/Queen.h"
#include "../datastructures/pieces/Bishop.h"
#include "../datastructures/pieces/Rook.h"
#include "../datastructures/pieces/Knight.h"

Board *PGNConverter::emptyBoard = new Board();

void PGNConverter::convert(std::string pgnString, Board *board) {
    emptyBoard->wipeBoard();
    // Parses the pgn string move by move ungreedily
    std::regex regEx(R"(([0-9]+\.\s.*?\s.*?\s|[0-9]+\.\s.*?\s.*|[0-9]+\.\s.*\s|[0-9]+\.\s.*))");
    auto regIterator = std::sregex_iterator(pgnString.cbegin(), pgnString.cend(), regEx);
    auto regEnd = std::sregex_iterator();

    while (regIterator != regEnd) {
        std::regex fullMoveRegEx(R"(^[0-9]+\.\s(.*?)\s?$)");
        std::regex newLine("(\n)");
        // Remove newlines in the middle of moves
        std::string regString = std::regex_replace(regIterator->str(), newLine, " ");
        std::smatch sm;
        // Get the specific moves being made
        std::regex_match(regString, sm, fullMoveRegEx);
        std::string bothMoves = sm[1];

        std::string whiteMove = bothMoves.substr(0, bothMoves.find(' '));
        playAlgebraicMove(WHITE, whiteMove, board);

        if (bothMoves.find(' ') != std::string::npos) {
            std::string blackMove = bothMoves.substr(bothMoves.find(' ') + 1, bothMoves.length());
            playAlgebraicMove(BLACK, blackMove, board);
        }

        board->printUnicodeBoard();
        regIterator++;
    }
}

void PGNConverter::playAlgebraicMove(Color currPlayer, std::string algebraicString, Board *board) {
    int moveType = PGNConverter::getAlgebraicMoveType(algebraicString);
    Position startingPosition{};
    Position endingPosition{};

    switch (moveType) {
        case CASTLE_MOVE_KING:
            startingPosition.row = currPlayer == WHITE ? 1 : 8;
            startingPosition.column = 'E';
            endingPosition.row = startingPosition.row;
            endingPosition.column = 'G';
            break;
        case CASTLE_MOVE_QUEEN:
            startingPosition.row = currPlayer == WHITE ? 1 : 8;
            startingPosition.column = 'E';
            endingPosition.row = startingPosition.row;
            endingPosition.column = 'C';
            break;
        case RESULT_MOVE:
            // The game has been decided either by forfeit or by the game state
            return;
        case PIECE_MOVE:
            getPieceOrPawnPosition(currPlayer, algebraicString, board, startingPosition, endingPosition);
            break;
        case PAWN_MOVE:
            getPieceOrPawnPosition(currPlayer, algebraicString, board, startingPosition, endingPosition);
            break;
        default:
            // Throw an exception since the pgn format is invalid
            throw std::invalid_argument("The pgn passed in is invalid.");
    }

    if (!board->movePiece(startingPosition, endingPosition, currPlayer)) {
        throw std::invalid_argument("The pgn passed in is invalid.");
    }
}

int PGNConverter::getAlgebraicMoveType(std::string algebraicString) {
    std::regex whiteSpace("\\s+");
    algebraicString = std::regex_replace(algebraicString, whiteSpace, "");

    if (algebraicString == "O-O") {
        return CASTLE_MOVE_KING;
    }

    if (algebraicString == "O-O-O") {
        return CASTLE_MOVE_QUEEN;
    }

    if (algebraicString == "1-0" || algebraicString == "0-1" || algebraicString == "1/2-1/2") {
        return RESULT_MOVE;
    }

    std::regex pieceRegEx("^[NKRQB]([1-8]|[a-h])?x?[a-h][1-8][+#]?$");
    std::smatch sm;
    std::regex_match(algebraicString, sm, pieceRegEx);

    if (sm.length()) {
        return PIECE_MOVE;
    }

    std::regex pawnRegEx("^[a-h]?x?[a-h][1-8](=[NBQR])?[+#]?$");
    std::regex_match(algebraicString, sm, pawnRegEx);

    if (sm.length()) {
        return PAWN_MOVE;
    }

    return INVALID_MOVE;
}

void PGNConverter::getPieceOrPawnPosition(Color currPlayer, std::string algebraicMove, Board *board, Position &start, Position &end) {
    std::regex whiteSpace("\\s+");
    algebraicMove = std::regex_replace(algebraicMove, whiteSpace, "");
    std::regex complexMove("^([NKBQR])?([a-h]|[1-8])?(x)?([a-h])([1-8])(=[NBQR])?[+#]?$");
    std::smatch matches;
    std::regex_search(algebraicMove, matches, complexMove);

    // Get all the relevant tokens from the above regex
    char CLIToken = matches[1].str()[0];
    char multiMoveInfo = (char)(toupper(matches[2].str()[0]));
    bool isExecution = matches[3].str()[0] == 'x';
    end.column = (char)(toupper(matches[4].str()[0]));
    end.row = matches[5].str()[0] - '0';

    if (CLIToken == '\0') {
        // Pawn move
        CLIToken = 'P';
    }

    if (multiMoveInfo != '\0') {
        // Get the specific token in this column/row
        if (multiMoveInfo >= 'A' && multiMoveInfo <= 'H') {
            for (int i = 1; i < 9; i++) {
                Position positionCandidate = {
                        multiMoveInfo,
                        i
                };
                Piece *pieceCandidate = board->getPiece(positionCandidate);
                if (pieceCandidate != nullptr && pieceCandidate->player == currPlayer && pieceCandidate->getCLIToken() == CLIToken) {
                    start = positionCandidate;
                    return;
                }
            }
        } else {
            for (unsigned i = 0; i < 8; i++) {
                int potentialRow = multiMoveInfo - '0';
                Position positionCandidate = {
                        (char)('a' + i),
                        potentialRow
                };
                Piece *pieceCandidate = board->getPiece(positionCandidate);
                if (pieceCandidate != nullptr && pieceCandidate->player == currPlayer && pieceCandidate->getCLIToken() == CLIToken) {
                    start = positionCandidate;
                    return;
                }
            }
        }
    } else {
        Piece *potentialPiece;
        if (CLIToken == 'P') {
            std::vector<int> potentialRows;
            std::vector<char> potentialCols;

            if (currPlayer == BLACK) {
                potentialRows.push_back(end.row + 1);
            } else {
                potentialRows.push_back(end.row - 1);
            }

            if (isExecution) {
                if (end.column == 'H') {
                    potentialCols.push_back('G');
                } else if (end.column == 'A') {
                    potentialCols.push_back('B');
                } else {
                    potentialCols.push_back((char) (end.column + 1));
                    potentialCols.push_back((char) (end.column - 1));
                }
            } else {
                potentialCols.push_back(end.column);

                if (currPlayer == BLACK) {
                    potentialRows.push_back(end.row + 2);
                } else {
                    potentialRows.push_back(end.row - 2);
                }
            }

            for (unsigned i = 0; i < potentialRows.size(); i++) {
                for (unsigned j = 0; j < potentialCols.size(); j++) {
                    Position positionCandidate = {
                            potentialCols[j],
                            potentialRows[i]
                    };
                    Piece *pieceCandidate = board->getPiece(positionCandidate);
                    if (pieceCandidate != nullptr && pieceCandidate->player == currPlayer && pieceCandidate->getCLIToken() == CLIToken) {
                        start = positionCandidate;
                        return;
                    }
                }
            }
        } else {
            switch (CLIToken) {
                case 'K':
                    potentialPiece = new King(end, currPlayer);
                    break;
                case 'Q':
                    potentialPiece = new Queen(end, currPlayer);
                    break;
                case 'B':
                    potentialPiece = new Bishop(end, currPlayer);
                    break;
                case 'R':
                    potentialPiece = new Rook(end, currPlayer);
                    break;
                case 'N':
                    potentialPiece = new Knight(end, currPlayer);
                    break;
            }

            std::vector<Position> potentialStartingPositions = potentialPiece->possibleMoves(*emptyBoard);

            for (unsigned i = 0; i < potentialStartingPositions.size(); i++) {
                Position positionCandidate = potentialStartingPositions[i];
                Piece *pieceCandidate = board->getPiece(positionCandidate);

                if (pieceCandidate != nullptr && pieceCandidate->player == currPlayer && pieceCandidate->getCLIToken() == CLIToken) {
                    start = positionCandidate;
                    return;
                }
            }
        }
    }
}
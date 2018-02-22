#include <gtest/gtest.h>
#include <datastructures/Board.h>
#include <datastructures/pieces/Rook.h>
#include <util/VectorComparator.h>
#include <datastructures/pieces/Pawn.h>

TEST(RookTests, EmptyBoard) {

    auto *board = new Board();
    board->wipeBoard();

    Rook *rook = new Rook({'E', 4}, WHITE);

    std::vector<Position> positions;
    positions.push_back({'F', 4});
    positions.push_back({'G', 4});
    positions.push_back({'H', 4});
    positions.push_back({'D', 4});
    positions.push_back({'C', 4});
    positions.push_back({'B', 4});
    positions.push_back({'A', 4});
    positions.push_back({'E', 5});
    positions.push_back({'E', 6});
    positions.push_back({'E', 7});
    positions.push_back({'E', 8});
    positions.push_back({'E', 3});
    positions.push_back({'E', 2});
    positions.push_back({'E', 1});

    board->placePiece(rook->currentPosition, rook);

    ASSERT_TRUE(VectorComparator::comparePositions(board->getPiece(rook->currentPosition)->possibleMoves(*board), positions));

    delete board;
    delete rook;

}

TEST(RookTests, BlockedByEnemies) {

    auto *board = new Board();
    board->wipeBoard();

    Rook *rook = new Rook({'E', 4}, WHITE);
    board->placePiece({'E', 5}, new Pawn({'E', 5}, BLACK));
    board->placePiece({'E', 3}, new Pawn({'E', 3}, BLACK));
    board->placePiece({'G', 4}, new Pawn({'G', 4}, BLACK));
    board->placePiece({'C', 4}, new Pawn({'C', 4}, BLACK));

    std::vector<Position> positions;
    positions.push_back({'F', 4});
    positions.push_back({'G', 4});
    positions.push_back({'D', 4});
    positions.push_back({'C', 4});
    positions.push_back({'E', 5});
    positions.push_back({'E', 3});

    board->placePiece(rook->currentPosition, rook);

    ASSERT_TRUE(VectorComparator::comparePositions(board->getPiece(rook->currentPosition)->possibleMoves(*board), positions));

    delete board;
    delete rook;

}

TEST(RookTests, BlockedByFriendly) {

    auto *board = new Board();
    board->wipeBoard();

    Rook *rook = new Rook({'E', 4}, WHITE);
    board->placePiece({'E', 5}, new Pawn({'E', 5}, BLACK));
    board->placePiece({'E', 3}, new Pawn({'E', 3}, BLACK));
    board->placePiece({'G', 4}, new Pawn({'G', 4}, BLACK));
    board->placePiece({'C', 4}, new Pawn({'C', 4}, BLACK));

    std::vector<Position> positions;
    positions.push_back({'F', 4});
    positions.push_back({'G', 4});
    positions.push_back({'D', 4});
    positions.push_back({'C', 4});
    positions.push_back({'E', 5});
    positions.push_back({'E', 3});

    board->placePiece(rook->currentPosition, rook);

    ASSERT_TRUE(VectorComparator::comparePositions(board->getPiece(rook->currentPosition)->possibleMoves(*board), positions));

    delete board;
    delete rook;

}

TEST(RookTests, UnicodeRepresentation) {

    Rook p = Rook({'E', 4}, BLACK);

    ASSERT_EQ(p.getUnicodeToken(), "\u2656");
    p.player = WHITE;
    ASSERT_EQ(p.getUnicodeToken(), "\u265C");

}

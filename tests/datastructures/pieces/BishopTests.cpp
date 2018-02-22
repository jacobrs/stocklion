#include <gtest/gtest.h>
#include <util/VectorComparator.h>
#include <datastructures/pieces/Pawn.h>
#include "datastructures/Board.h"
#include "datastructures/pieces/Bishop.h"

TEST(BishopTests, MiddleOpenBoardPossibleMoves) {
    auto board = new Board;

    board->wipeBoard();
    Bishop *bishop = new Bishop({'E', 4}, WHITE);
    board->placePiece({'E', 4}, bishop);

    ASSERT_EQ(board->getPiece({'E', 4}), bishop);

    std::vector<Position> positions;
    positions.push_back({'D', 5});
    positions.push_back({'C', 6});
    positions.push_back({'B', 7});
    positions.push_back({'A', 8});
    positions.push_back({'F', 3});
    positions.push_back({'G', 2});
    positions.push_back({'H', 1});
    positions.push_back({'D', 3});
    positions.push_back({'C', 2});
    positions.push_back({'B', 1});
    positions.push_back({'F', 5});
    positions.push_back({'G', 6});
    positions.push_back({'H', 7});

    ASSERT_TRUE(board->getPiece({'E', 4}) == bishop);
    ASSERT_TRUE(VectorComparator::comparePositions(board->getPiece({'E', 4})->possibleMoves(*board), positions));

    delete board;
    delete bishop;
}

TEST(BishopTests, BlockedByEnemy) {
    auto board = new Board;

    board->wipeBoard();
    Bishop *bishop = new Bishop({'E', 4}, WHITE);
    board->placePiece({'E', 4}, bishop);
    board->placePiece({'B', 7}, new Pawn({'B', 7}, BLACK));
    board->placePiece({'F', 5}, new Pawn({'F', 5}, BLACK));
    board->placePiece({'G', 2}, new Pawn({'G', 2}, BLACK));
    board->placePiece({'C', 2}, new Pawn({'C', 2}, BLACK));

    ASSERT_EQ(board->getPiece({'E', 4}), bishop);

    std::vector<Position> positions;
    positions.push_back({'D', 5});
    positions.push_back({'C', 6});
    positions.push_back({'B', 7});
    positions.push_back({'F', 3});
    positions.push_back({'G', 2});
    positions.push_back({'D', 3});
    positions.push_back({'C', 2});
    positions.push_back({'F', 5});

    ASSERT_TRUE(board->getPiece({'E', 4}) == bishop);
    ASSERT_TRUE(VectorComparator::comparePositions(board->getPiece({'E', 4})->possibleMoves(*board), positions));

    delete board;
    delete bishop;

}

TEST(BishopTests, BlockedByFriendly) {
    auto board = new Board;

    board->wipeBoard();
    Bishop *bishop = new Bishop({'E', 4}, WHITE);
    board->placePiece({'E', 4}, bishop);
    board->placePiece({'B', 7}, new Pawn({'B', 7}, WHITE));
    board->placePiece({'F', 5}, new Pawn({'F', 5}, WHITE));
    board->placePiece({'G', 2}, new Pawn({'G', 2}, WHITE));

    ASSERT_EQ(board->getPiece({'E', 4}), bishop);

    std::vector<Position> positions;
    positions.push_back({'D', 5});
    positions.push_back({'C', 6});
    positions.push_back({'F', 3});
    positions.push_back({'D', 3});
    positions.push_back({'C', 2});
    positions.push_back({'B', 1});

    ASSERT_TRUE(board->getPiece({'E', 4}) == bishop);
    ASSERT_TRUE(VectorComparator::comparePositions(board->getPiece({'E', 4})->possibleMoves(*board), positions));

    delete board;
    delete bishop;

}

TEST(BishopTests, UnicodeRepresentation) {

    Bishop b = Bishop({'E', 4}, WHITE);
    ASSERT_EQ(b.getUnicodeToken(), "\u265D");

    b = Bishop({'E', 4}, BLACK);
    ASSERT_EQ(b.getUnicodeToken(), "\u2657");

}

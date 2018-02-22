#include <gtest/gtest.h>
#include <datastructures/Board.h>
#include <datastructures/pieces/Knight.h>
#include <util/VectorComparator.h>
#include <datastructures/pieces/Pawn.h>

TEST(KnightTests, EmptyBoard) {

    auto *board = new Board();
    board->wipeBoard();
    Knight *knight = new Knight({'E', 4}, WHITE);

    std::vector<Position> positions;
    positions.push_back({'D',6});
    positions.push_back({'F',6});
    positions.push_back({'D',2});
    positions.push_back({'F',2});
    positions.push_back({'C',3});
    positions.push_back({'C',5});
    positions.push_back({'G',3});
    positions.push_back({'G',5});

    board->placePiece(knight->currentPosition, knight);

    ASSERT_TRUE(VectorComparator::comparePositions(board->getPiece(knight->currentPosition)->possibleMoves(*board), positions));

    delete board;
    delete knight;

}

TEST(KnightTests, BlockedByEnemies) {

    auto *board = new Board();
    board->wipeBoard();
    Knight *knight = new Knight({'E', 4}, WHITE);

    board->placePiece({'D', 6}, new Pawn({'D', 6}, BLACK));
    board->placePiece({'D', 2}, new Pawn({'D', 2}, BLACK));
    board->placePiece({'F', 6}, new Pawn({'F', 6}, BLACK));
    board->placePiece({'F', 2}, new Pawn({'F', 2}, BLACK));
    board->placePiece({'C', 3}, new Pawn({'C', 3}, BLACK));
    board->placePiece({'C', 5}, new Pawn({'C', 5}, BLACK));
    board->placePiece({'G', 3}, new Pawn({'G', 3}, BLACK));
    board->placePiece({'G', 5}, new Pawn({'G', 5}, BLACK));

    std::vector<Position> positions;
    positions.push_back({'D',6});
    positions.push_back({'F',6});
    positions.push_back({'D',2});
    positions.push_back({'F',2});
    positions.push_back({'C',3});
    positions.push_back({'C',5});
    positions.push_back({'G',3});
    positions.push_back({'G',5});

    board->placePiece(knight->currentPosition, knight);

    ASSERT_TRUE(VectorComparator::comparePositions(board->getPiece(knight->currentPosition)->possibleMoves(*board), positions));

    delete board;
    delete knight;

}

TEST(KnightTests, BlockedByFriendlies) {

    auto *board = new Board();
    board->wipeBoard();
    Knight *knight = new Knight({'E', 4}, WHITE);

    board->placePiece({'D', 6}, new Pawn({'D', 6}, WHITE));
    board->placePiece({'D', 2}, new Pawn({'D', 2}, WHITE));
    board->placePiece({'F', 6}, new Pawn({'F', 6}, WHITE));
    board->placePiece({'F', 2}, new Pawn({'F', 2}, WHITE));
    board->placePiece({'C', 3}, new Pawn({'C', 3}, WHITE));
    board->placePiece({'C', 5}, new Pawn({'C', 5}, WHITE));
    board->placePiece({'G', 3}, new Pawn({'G', 3}, WHITE));
    board->placePiece({'G', 5}, new Pawn({'G', 5}, WHITE));

    std::vector<Position> positions;

    board->placePiece(knight->currentPosition, knight);

    ASSERT_TRUE(VectorComparator::comparePositions(board->getPiece(knight->currentPosition)->possibleMoves(*board), positions));

    delete board;
    delete knight;

}

TEST(KnightTests, UnicodeRepresentation) {

    Knight p = Knight({'E', 4}, BLACK);

    ASSERT_EQ(p.getUnicodeToken(), "\u2658");
    p.player = WHITE;
    ASSERT_EQ(p.getUnicodeToken(), "\u265E");

}

#include <gtest/gtest.h>
#include <datastructures/Board.h>
#include <datastructures/pieces/Pawn.h>
#include <util/VectorComparator.h>

TEST(PawnTests, CaptureMoves) {

    auto *board = new Board();
    Pawn *p = new Pawn({'E', 7}, BLACK);

    std::vector<Position> positions;
    positions.push_back({'E', 6});
    positions.push_back({'E', 5});

    board->placePiece({'E', 7}, p);

    ASSERT_TRUE(VectorComparator::comparePositions(board->getPiece({'E', 7})->possibleMoves(*board), positions));

    Pawn *left = new Pawn({'D', 6}, WHITE);
    Pawn *right = new Pawn({'F', 6}, WHITE);
    board->placePiece(left->currentPosition, left);
    board->placePiece(right->currentPosition, right);

    positions.push_back({'D', 6});
    positions.push_back({'F', 6});

    ASSERT_TRUE(VectorComparator::comparePositions(board->getPiece({'E', 7})->possibleMoves(*board), positions));

    delete board;
    delete left;
    delete right;
    delete p;

}

TEST(PawnTests, UnicodeRepresentation) {

    Pawn p = Pawn({'E', 4}, BLACK);

    ASSERT_EQ(p.getUnicodeToken(), "\u2659");
    p.player = WHITE;
    ASSERT_EQ(p.getUnicodeToken(), "\u265F");

}

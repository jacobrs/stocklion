#include <gtest/gtest.h>
#include <datastructures/Board.h>

TEST(BoardTests, BoardComparatorSameBoards) {

    auto board1 = new Board();
    auto board2 = new Board();

    ASSERT_TRUE(*board1 == *board2);
    ASSERT_FALSE(*board1 != *board2);

}

TEST(BoardTests, BoardComparatorDifferentBoards) {

    auto board1 = new Board();
    auto board2 = new Board();
    Position from = {'E', 2};
    Position to = {'E', 4};
    board2->movePiece(from, to, WHITE);

    ASSERT_FALSE(*board1 == *board2);
    ASSERT_TRUE(*board1 != *board2);

}

#include <gtest/gtest.h>
#include <datastructures/Board.h>
#include <datastructures/pieces/Knight.h>

TEST(BoardTests, BoardComparatorSameBoards) {

    auto board1 = new Board();
    auto board2 = new Board();
    ASSERT_TRUE(*board1 == *board2);
    ASSERT_FALSE(*board1 != *board2);

    board1->placePiece({'E', 4}, new Knight({'E', 4}, WHITE));
    board2->placePiece({'E', 4}, new Knight({'E', 4}, WHITE));
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

    board1->wipeBoard();
    board2->wipeBoard();

    board1->placePiece({'E', 4}, new Knight({'E', 4}, WHITE));
    board2->placePiece({'E', 4}, new Knight({'E', 4}, BLACK));
    ASSERT_FALSE(*board1 == *board2);
    ASSERT_TRUE(*board1 != *board2);

}

TEST(BoardTests, OutputNoCrash) {

    auto board = new Board();

    board->printBoard();
    board->printUnicodeBoard();

    delete board;

    SUCCEED();

}

TEST(BoardTests, InvalidMove) {

    auto board = new Board();

    Position from = {'E', 4}; Position to = {'E', 3};
    ASSERT_FALSE(board->movePiece(from, to, WHITE));
    from = {'E', 2}; to = {'E', 5};
    ASSERT_FALSE(board->movePiece(from, to, WHITE));
    from = {'E', 7}; to = {'E', 6};
    ASSERT_FALSE(board->movePiece(from, to, WHITE));

    delete board;

}

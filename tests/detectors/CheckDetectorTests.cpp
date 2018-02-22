#include <gtest/gtest.h>
#include <datastructures/Board.h>
#include <detectors/CheckDetector.h>

TEST(CheckDetectorTests, QueenCheck) {

    auto *board = new Board();
    ASSERT_FALSE(CheckDetector::playerInCheck(BLACK, *board));
    ASSERT_FALSE(CheckDetector::playerInCheck(WHITE, *board));

    Position from = {'E', 2};
    Position to = {'E', 3};
    board->movePiece(from, to, WHITE);
    from = {'F',7}; to = {'F', 6};
    board->movePiece(from, to, BLACK);
    ASSERT_FALSE(CheckDetector::playerInCheck(BLACK, *board));
    ASSERT_FALSE(CheckDetector::playerInCheck(WHITE, *board));

    from = {'D',1}; to = {'H', 5};
    board->movePiece(from, to, WHITE);
    ASSERT_TRUE(CheckDetector::playerInCheck(BLACK, *board));
    ASSERT_FALSE(CheckDetector::playerInCheck(WHITE, *board));

    from = {'G',7}; to = {'G', 6};
    board->movePiece(from, to, BLACK);
    ASSERT_FALSE(CheckDetector::playerInCheck(BLACK, *board));
    ASSERT_FALSE(CheckDetector::playerInCheck(WHITE, *board));

    delete board;

}

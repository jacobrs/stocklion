#include <gtest/gtest.h>
#include <datastructures/Board.h>
#include <datastructures/pieces/Rook.h>
#include <util/VectorComparator.h>

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


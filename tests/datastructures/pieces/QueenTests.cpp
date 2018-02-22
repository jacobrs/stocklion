#include <gtest/gtest.h>
#include <datastructures/Board.h>
#include <datastructures/pieces/Queen.h>
#include <util/VectorComparator.h>
#include <datastructures/pieces/Pawn.h>

TEST(QueenTests, EmptyBoard){

    auto board = new Board;

    board->wipeBoard();
    Queen *queen = new Queen({'E', 4}, WHITE);
    board->placePiece({'E', 4}, queen);

    ASSERT_EQ(board->getPiece({'E', 4}), queen);

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

    board->placePiece(queen->currentPosition, queen);

    ASSERT_TRUE(VectorComparator::comparePositions(board->getPiece(queen->currentPosition)->possibleMoves(*board), positions));

    delete board;
    delete queen;

}

TEST(QueenTests, BlockedByEnemies) {

    auto board = new Board;

    board->wipeBoard();
    Queen *queen = new Queen({'E', 4}, WHITE);
    board->placePiece({'E', 4}, queen);
    board->placePiece({'B', 7}, new Pawn({'B', 7}, BLACK));
    board->placePiece({'F', 5}, new Pawn({'F', 5}, BLACK));
    board->placePiece({'G', 2}, new Pawn({'G', 2}, BLACK));
    board->placePiece({'C', 2}, new Pawn({'C', 2}, BLACK));
    board->placePiece({'E', 5}, new Pawn({'E', 5}, BLACK));
    board->placePiece({'E', 3}, new Pawn({'E', 3}, BLACK));
    board->placePiece({'G', 4}, new Pawn({'G', 4}, BLACK));
    board->placePiece({'C', 4}, new Pawn({'C', 4}, BLACK));

    ASSERT_EQ(board->getPiece({'E', 4}), queen);

    std::vector<Position> positions;
    positions.push_back({'D', 5});
    positions.push_back({'C', 6});
    positions.push_back({'B', 7});
    positions.push_back({'F', 3});
    positions.push_back({'G', 2});
    positions.push_back({'D', 3});
    positions.push_back({'C', 2});
    positions.push_back({'F', 5});
    positions.push_back({'F', 4});
    positions.push_back({'G', 4});
    positions.push_back({'D', 4});
    positions.push_back({'C', 4});
    positions.push_back({'E', 5});
    positions.push_back({'E', 3});

    ASSERT_TRUE(VectorComparator::comparePositions(board->getPiece(queen->currentPosition)->possibleMoves(*board), positions));

    delete board;
    delete queen;

}

TEST(QueenTests, BlockedByFriendly) {

    auto board = new Board;

    board->wipeBoard();
    Queen *queen = new Queen({'E', 4}, WHITE);
    board->placePiece({'E', 4}, queen);
    board->placePiece({'B', 7}, new Pawn({'B', 7}, WHITE));
    board->placePiece({'F', 5}, new Pawn({'F', 5}, WHITE));
    board->placePiece({'G', 2}, new Pawn({'G', 2}, WHITE));
    board->placePiece({'E', 5}, new Pawn({'E', 5}, WHITE));
    board->placePiece({'E', 3}, new Pawn({'E', 3}, WHITE));
    board->placePiece({'G', 4}, new Pawn({'G', 4}, WHITE));
    board->placePiece({'C', 4}, new Pawn({'C', 4}, WHITE));

    std::vector<Position> positions;
    positions.push_back({'D', 5});
    positions.push_back({'C', 6});
    positions.push_back({'F', 3});
    positions.push_back({'D', 3});
    positions.push_back({'C', 2});
    positions.push_back({'B', 1});
    positions.push_back({'F', 4});
    positions.push_back({'D', 4});

    ASSERT_TRUE(VectorComparator::comparePositions(board->getPiece(queen->currentPosition)->possibleMoves(*board), positions));

    delete board;
    delete queen;

}

TEST(QueenTests, UnicodeRepresentation) {

    Queen p = Queen({'E', 4}, BLACK);

    ASSERT_EQ(p.getUnicodeToken(), "\u2655");
    p.player = WHITE;
    ASSERT_EQ(p.getUnicodeToken(), "\u265B");

}

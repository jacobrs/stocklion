#include <gtest/gtest.h>
#include <datastructures/Board.h>
#include <datastructures/pieces/King.h>
#include <util/VectorComparator.h>
#include <datastructures/pieces/Pawn.h>

TEST(KingTests, EmptyBoard) {

    auto *board = new Board();
    King *king = new King({'E', 4}, WHITE);

    std::vector<Position> positions;
    positions.push_back({'D',4});
    positions.push_back({'D',3});
    positions.push_back({'D',5});
    positions.push_back({'F',4});
    positions.push_back({'F',3});
    positions.push_back({'F',5});
    positions.push_back({'E',5});
    positions.push_back({'E',3});

    board->placePiece(king->currentPosition, king);

    ASSERT_TRUE(VectorComparator::comparePositions(board->getPiece(king->currentPosition)->possibleMoves(*board), positions));

    delete board;
    delete king;

}

TEST(KingTests, BlockedByEnemies) {

    auto *board = new Board();
    King *king = new King({'E', 4}, WHITE);
    board->placePiece({'D', 4}, new Pawn({'D', 4}, BLACK));
    board->placePiece({'D', 3}, new Pawn({'D', 3}, BLACK));
    board->placePiece({'D', 5}, new Pawn({'D', 5}, BLACK));
    board->placePiece({'F', 4}, new Pawn({'F', 4}, BLACK));
    board->placePiece({'F', 3}, new Pawn({'F', 3}, BLACK));
    board->placePiece({'F', 5}, new Pawn({'F', 5}, BLACK));
    board->placePiece({'E', 5}, new Pawn({'E', 5}, BLACK));
    board->placePiece({'E', 3}, new Pawn({'E', 3}, BLACK));

    std::vector<Position> positions;
    positions.push_back({'D',4});
    positions.push_back({'D',3});
    positions.push_back({'D',5});
    positions.push_back({'F',4});
    positions.push_back({'F',3});
    positions.push_back({'F',5});
    positions.push_back({'E',5});
    positions.push_back({'E',3});

    board->placePiece(king->currentPosition, king);

    ASSERT_TRUE(VectorComparator::comparePositions(board->getPiece(king->currentPosition)->possibleMoves(*board), positions));

    delete board;
    delete king;

}

TEST(KingTests, BlockedByFriendly) {

    auto *board = new Board();
    King *king = new King({'E', 4}, WHITE);
    board->placePiece({'D', 4}, new Pawn({'D', 4}, WHITE));
    board->placePiece({'D', 3}, new Pawn({'D', 3}, WHITE));
    board->placePiece({'D', 5}, new Pawn({'D', 5}, WHITE));
    board->placePiece({'F', 4}, new Pawn({'F', 4}, WHITE));
    board->placePiece({'F', 3}, new Pawn({'F', 3}, WHITE));
    board->placePiece({'F', 5}, new Pawn({'F', 5}, WHITE));
    board->placePiece({'E', 5}, new Pawn({'E', 5}, WHITE));
    board->placePiece({'E', 3}, new Pawn({'E', 3}, WHITE));

    std::vector<Position> positions;

    board->placePiece(king->currentPosition, king);

    ASSERT_TRUE(VectorComparator::comparePositions(board->getPiece(king->currentPosition)->possibleMoves(*board), positions));

    delete board;
    delete king;

}

TEST(KingTests, UnicodeRepresentation) {

    King p = King({'E', 4}, BLACK);

    ASSERT_EQ(p.getUnicodeToken(), "\u2654");
    p.player = WHITE;
    ASSERT_EQ(p.getUnicodeToken(), "\u265A");

}

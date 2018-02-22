#include <gtest/gtest.h>
#include <datastructures/pieces/Pawn.h>
#include <datastructures/pieces/Bishop.h>

TEST(PieceTests, PositionComparatorsSamePositions) {

    Position p1 = {'E', 4};
    Position p2 = {'E', 4};

    ASSERT_TRUE(p1 == p2);
    ASSERT_FALSE(p1 != p2);

}

TEST(PieceTests, PositionComparatorsDifferentPositions) {
    Position p1 = {'E', 4};
    Position p2 = {'E', 3};
    Position p3 = {'A', 4};

    ASSERT_FALSE(p1 == p2);
    ASSERT_FALSE(p1 == p3);
    ASSERT_TRUE(p1 != p2);
    ASSERT_TRUE(p1 != p3);
}

TEST(PieceTests, PieceComparatorSamePieces) {

    Pawn p1 = Pawn({'E', 4}, WHITE);
    Pawn p2 = Pawn({'E', 4}, WHITE);

    ASSERT_TRUE(p1 == p2);
    ASSERT_FALSE(p1 != p2);

}

TEST(PieceTests, PieceComparatorDifferentPieces) {

    Pawn p1 = Pawn({'E', 4}, WHITE);
    Pawn p2 = Pawn({'E', 4}, BLACK);

    ASSERT_FALSE(p1 == p2);
    ASSERT_TRUE(p1 != p2);
    p2 = Pawn({'E', 3}, WHITE);
    ASSERT_FALSE(p1 == p2);
    ASSERT_TRUE(p1 != p2);
    Bishop b1 = Bishop({'E', 4}, WHITE);
    ASSERT_FALSE(p1 == b1);
    ASSERT_TRUE(p1 != b1);

}
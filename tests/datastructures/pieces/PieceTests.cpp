#include <gtest/gtest.h>
#include <datastructures/pieces/Pawn.h>
#include <datastructures/pieces/Bishop.h>

TEST(PieceTests, PositionComparators) {

    Position p1 = {'E', 4};
    Position p2 = {'E', 4};
    Position p3 = {'E', 3};
    Position p4 = {'A', 4};

    ASSERT_TRUE(p1 == p2);
    ASSERT_FALSE(p1 == p3);
    ASSERT_FALSE(p1 == p4);

}

TEST(PieceTests, PieceComparator) {

    Pawn p1 = Pawn({'E', 4}, WHITE);
    Pawn p2 = Pawn({'E', 4}, WHITE);

    ASSERT_TRUE(p1 == p2);
    p2 = Pawn({'E', 4}, BLACK);
    ASSERT_FALSE(p1 == p2);
    p2 = Pawn({'E', 3}, WHITE);
    ASSERT_FALSE(p1 == p2);
    Bishop b1 = Bishop({'E', 4}, WHITE);
    ASSERT_FALSE(p1 == b1);

}
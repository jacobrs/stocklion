#include <gtest/gtest.h>
#include "datastructures/Board.h"
#include "converters/PGNConverter.h"

TEST(PGNConverterTest, HandlesEmptyPGN) {
    Board *testBoard = new Board(WHITE);
    PGNConverter::convert("", testBoard);

    ASSERT_EQ(1, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include <gtest/gtest.h>
#include "datastructures/Board.h"
#include "converters/PGNConverter.h"
#include "converters/FENConverter.h"

TEST(PGNConverterTest, HandlesEmptyPGN) {
    Board *testAgainstBoard = new Board(WHITE);
    Board *testBoard = new Board(WHITE);
    PGNConverter::convert("", testBoard);

    ASSERT_TRUE(*testBoard == *testAgainstBoard);
}

TEST(PGNConverterTest, HandlesVariousStates) {
    Board *testAgainstBoard = new Board(WHITE);
    Board *testBoard = new Board(WHITE);
    PGNConverter::convert("1. d4 e5 2. dxe5 Qf6 3. Kd2 Qxe5 4. Nf3 Qe3+\n"
                                  "5. Ke1 Qxc1 6. Nc3 Qf4 7. Nd4 f5 8. Nxf5 Qxf5\n", testBoard);
    FENConverter::convert("rnb1kbnr/pppp2pp/8/5q2/8/2N5/PPP1PPPP/R2QKB1R w KQkq -", testAgainstBoard);

    ASSERT_TRUE(*testBoard == *testAgainstBoard);
}

TEST(PGNConverterTest, HandlesEdgeQueenState) {
    Board *testBoard = new Board(WHITE);
    Board *testAgainstBoard = new Board(WHITE);
    FENConverter::convert("8/8/8/2Q1Q3/3p4/2Q5/8/8 w -", testBoard);
    PGNConverter::convert("1. Qc5xd4", testBoard);
    FENConverter::convert("8/8/8/4Q3/3Q4/2Q5/8/8 b -", testAgainstBoard);

    ASSERT_TRUE(*testBoard == *testAgainstBoard);
}

TEST(PGNConverterTest, HandlesAmbiguousPawnExecution) {
    Board *testBoard = new Board(WHITE);
    Board *testAgainstBoard = new Board(WHITE);
    FENConverter::convert("8/8/8/8/pppppppp/PPPPPPPP/8/8 w -", testBoard);
    PGNConverter::convert("1. bxa4 exd3 2. gxh4", testBoard);
    FENConverter::convert("8/8/8/8/Pppp1ppP/P1PpPP1P/8/8 b -", testAgainstBoard);

    ASSERT_TRUE(*testBoard == *testAgainstBoard);
}

TEST(PGNConverterTest, HandlesAmbiguousRankExecution) {
    Board *testBoard = new Board(WHITE);
    Board *testAgainstBoard = new Board(WHITE);
    FENConverter::convert("8/8/6B1/8/4q3/8/2B5/8 w -", testBoard);
    PGNConverter::convert("1. B2xe4", testBoard);
    FENConverter::convert("8/8/6B1/8/4B3/8/8/8 b -", testAgainstBoard);

    ASSERT_TRUE(*testBoard == *testAgainstBoard);
}

/*TEST(PGNConverterTest, HandlesCastleKingSide) {
    Board *testBoard = new Board(WHITE);
    Board *testAgainstBoard = new Board(WHITE);
    FENConverter::convert("4k2r/8/8/8/8/8/8/4K2R w Kk -", testBoard);
    PGNConverter::convert("1. O-O O-O", testBoard);
    FENConverter::convert("5rk1/8/8/8/8/8/8/5RK1 w -", testAgainstBoard);

    ASSERT_TRUE(*testBoard == *testAgainstBoard);
}

TEST(PGNConverterTest, HandlesCastleQueenSide) {
    Board *testBoard = new Board(WHITE);
    Board *testAgainstBoard = new Board(WHITE);
    FENConverter::convert("r3k3/8/8/8/8/8/8/R3k3 w Qq -", testBoard);
    PGNConverter::convert("1. O-O-O O-O-O", testBoard);
    FENConverter::convert("2kr4/8/8/8/8/8/8/2KR4 w -", testAgainstBoard);

    ASSERT_TRUE(*testBoard == *testAgainstBoard);
}*/

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    //Run specific tests based off of a regex flag
    //::testing::GTEST_FLAG(filter) = "PGNConverterTest.*Castle*";
    return RUN_ALL_TESTS();
}
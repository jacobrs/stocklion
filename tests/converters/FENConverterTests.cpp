#include <gtest/gtest.h>
#include <converters/FENConverter.h>

TEST(FENConverterTests, InitialBoardState) {

    auto *board = new Board();
    auto *interpretedBoard = new Board();
    FENConverter::convert("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -", interpretedBoard);

    ASSERT_TRUE(*board == *interpretedBoard);

}

TEST(FENConverterTests, InvalidString) {
    testing::internal::CaptureStdout();

    std::string fen = "abcaljfgdahsjgbjadsbgjdakghlksdfhgklflhdabs";

    auto *interpretedBoard = new Board();
    FENConverter::convert(fen, interpretedBoard);

    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("Error converting board from FEN " + fen + "\n", output);
}
cmake_minimum_required(VERSION 3.9)
project(stocklion)

set(CMAKE_CXX_STANDARD 11)

add_executable(stocklion main.cpp datastructures/pieces/Piece.cpp datastructures/pieces/Piece.h datastructures/pieces/Pawn.cpp datastructures/pieces/Pawn.h datastructures/pieces/Knight.cpp datastructures/pieces/Knight.h datastructures/pieces/Rook.cpp datastructures/pieces/Rook.h datastructures/pieces/Bishop.cpp datastructures/pieces/Bishop.h datastructures/pieces/King.cpp datastructures/pieces/King.h datastructures/pieces/Queen.cpp datastructures/pieces/Queen.h)
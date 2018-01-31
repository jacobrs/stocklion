cmake_minimum_required(VERSION 3.9)
project(stocklion)

set(CMAKE_CXX_STANDARD 11)

add_executable(stocklion main.cpp datastructures/Piece.cpp datastructures/Piece.h datastructures/Pawn.cpp datastructures/Pawn.h datastructures/Knight.cpp datastructures/Knight.h datastructures/Rook.cpp datastructures/Rook.h datastructures/Bishop.cpp datastructures/Bishop.h datastructures/King.cpp datastructures/King.h datastructures/Queen.cpp datastructures/Queen.h)
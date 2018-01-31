cmake_minimum_required(VERSION 3.9)
project(stocklion)

set(CMAKE_CXX_STANDARD 11)

add_executable(stocklion main.cpp datastructures/Piece.cpp datastructures/Piece.h datastructures/Pieces.cpp datastructures/Pieces.h)
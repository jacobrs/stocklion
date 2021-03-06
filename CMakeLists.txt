cmake_minimum_required(VERSION 3.9)
project(stocklion)

set(CMAKE_CXX_STANDARD 11)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed. Eg
include_directories(./)
add_executable(stocklion main.cpp datastructures/pieces/Piece.cpp datastructures/pieces/Piece.h datastructures/pieces/Pawn.cpp datastructures/pieces/Pawn.h datastructures/pieces/Knight.cpp datastructures/pieces/Knight.h datastructures/pieces/Rook.cpp datastructures/pieces/Rook.h datastructures/pieces/Bishop.cpp datastructures/pieces/Bishop.h datastructures/pieces/King.cpp datastructures/pieces/King.h datastructures/pieces/Queen.cpp datastructures/pieces/Queen.h datastructures/Board.cpp datastructures/Board.h converters/FENConverter.cpp converters/FENConverter.h converters/PGNConverter.h converters/PGNConverter.cpp util/UnicodeTable.h util/UnicodeTable.cpp detectors/CheckDetector.cpp detectors/CheckDetector.h util/VectorComparator.cpp util/VectorComparator.h)

add_executable(stocklion_tests tests/converters/PGNConverterTests.cpp datastructures/pieces/Piece.cpp datastructures/pieces/Piece.h datastructures/pieces/Pawn.cpp datastructures/pieces/Pawn.h datastructures/pieces/Knight.cpp datastructures/pieces/Knight.h datastructures/pieces/Rook.cpp datastructures/pieces/Rook.h datastructures/pieces/Bishop.cpp datastructures/pieces/Bishop.h datastructures/pieces/King.cpp datastructures/pieces/King.h datastructures/pieces/Queen.cpp datastructures/pieces/Queen.h datastructures/Board.cpp datastructures/Board.h converters/FENConverter.cpp converters/FENConverter.h converters/PGNConverter.h converters/PGNConverter.cpp util/UnicodeTable.h util/UnicodeTable.cpp detectors/CheckDetector.cpp detectors/CheckDetector.h tests/datastructures/pieces/BishopTests.cpp util/VectorComparator.cpp util/VectorComparator.h tests/datastructures/pieces/PieceTests.cpp tests/datastructures/BoardTests.cpp tests/datastructures/pieces/PawnTests.cpp tests/util/VectorComparatorTests.cpp tests/converters/FENConverterTests.cpp tests/datastructures/pieces/KingTests.cpp tests/datastructures/pieces/KnightTests.cpp tests/datastructures/pieces/RookTests.cpp tests/datastructures/pieces/QueenTests.cpp tests/detectors/CheckDetectorTests.cpp)
target_link_libraries(stocklion_tests gtest gmock_main)
add_test(NAME test_stocklion COMMAND stocklion_tests)

SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")

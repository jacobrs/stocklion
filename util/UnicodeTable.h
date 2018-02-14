#ifndef STOCKLION_UNICODE_TABLE_H
#define STOCKLION_UNICODE_TABLE_H

#include <string>
#include <map>
#include "../datastructures/Board.h"

enum rowSection {
    TOP,
    MIDDLE,
    BOTTOM
};

class UnicodeTable {
private:
    static const std::map<std::string, char32_t> UNICODE_CHARS;
public:
    static void printLine(rowSection , int);
    static void printChar(std::string);
    static void printChar32(char32_t);
};

#endif

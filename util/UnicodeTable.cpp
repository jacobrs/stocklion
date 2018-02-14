#include <iostream>
#include <codecvt>
#include "UnicodeTable.h"

const std::map<std::string, char32_t> UnicodeTable::UNICODE_CHARS = {
        { "VERTICAL_LINE", U'\u2502' },
        { "HORIZONTAL_LINE", U'\u2500' },
        { "LEFT_JOINT", U'\u251C' },
        { "RIGHT_JOINT", U'\u2524' },
        { "BOTTOM_JOINT", U'\u2534' },
        { "TOP_JOINT", U'\u252C' },
        { "MIDDLE_JOINT", U'\u253C' },
        { "TOP_RIGHT_JOINT", U'\u2510' },
        { "TOP_LEFT_JOINT", U'\u250C' },
        { "BOTTOM_LEFT_JOINT", U'\u2514' },
        { "BOTTOM_RIGHT_JOINT", U'\u2518' }
};

void UnicodeTable::printLine(rowSection rowName, int length) {
    std::string leftMostSymbol;
    std::string middleSymbols;
    std::string rightMostSymbol;

    switch (rowName) {
        case TOP:
            leftMostSymbol = "TOP_LEFT_JOINT";
            middleSymbols = "TOP_JOINT";
            rightMostSymbol = "TOP_RIGHT_JOINT";
            break;
        case BOTTOM:
            leftMostSymbol = "BOTTOM_LEFT_JOINT";
            middleSymbols = "BOTTOM_JOINT";
            rightMostSymbol = "BOTTOM_RIGHT_JOINT";
            break;
        case MIDDLE:
            leftMostSymbol = "LEFT_JOINT";
            middleSymbols = "MIDDLE_JOINT";
            rightMostSymbol = "RIGHT_JOINT";
            break;
    }

    for (unsigned i = 0; i < length; i++) {
        if (i == 0) {
            printChar(leftMostSymbol);
            printChar("HORIZONTAL_LINE");
            printChar("HORIZONTAL_LINE");
            printChar("HORIZONTAL_LINE");
        } else if (i == length - 1) {
            printChar(rightMostSymbol);
        } else {
            printChar(middleSymbols);
            printChar("HORIZONTAL_LINE");
            printChar("HORIZONTAL_LINE");
            printChar("HORIZONTAL_LINE");
        }
    }
}

void UnicodeTable::printChar(std::string charName) {
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> convert;
    std::cout << convert.to_bytes(UNICODE_CHARS.at(charName));
}

void UnicodeTable::printChar32(char32_t charUnicode) {
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> convert;
    std::cout << convert.to_bytes(charUnicode);
}
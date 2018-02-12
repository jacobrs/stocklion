#include <iostream>
#include <codecvt>
#include "UnicodeTable.h"

void UnicodeTable::printLine(std::string rowName, int length) {

}

void UnicodeTable::printChar(std::string charName) {
    const char32_t VL = U'\u2502';
    const char32_t HL = U'\u2500';
    const char32_t LJ = U'\u251C';
    const char32_t RJ = U'\u2524';
    const char32_t MJ = U'\u253C';
    const char32_t BJ = U'\u2534';
    const char32_t TJ = U'\u252C';
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> convert;


}
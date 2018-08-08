#include "utf8Util.h"



size_t utf8Length(char initChar) {
    if ((initChar & 0x80) == 0) {
        // 0zzzzzzz  1 byte
        return 1;
    } else if ((initChar & 0xe0) == 0xc0) {
        // 110yyyyy  2 bytes
        return 2;
    } else if ((initChar & 0xf0) == 0xe0) {
        // 1110xxxx  3 bytes
        return 3;
    } else if ((initChar & 0xf8) == 0xf0) {
        // 11110www  4 bytes
        return 4;
    } else {
        // Invalid  return 0
        return 0;
    }
}

size_t findMaxUtf8Pos(char* buffer, size_t bufferSize) {
    char* lastPos = buffer + bufferSize - 1;

    while (utf8Length(*lastPos) == 0) {
        --lastPos;
    }

    size_t lastLength = utf8Length(*lastPos);

    size_t exceptLastPos = lastPos - buffer;
    size_t includeLastPos = exceptLastPos + lastLength;

    if (includeLastPos <= bufferSize) {
        return includeLastPos;
    } else {
        return exceptLastPos;
    }




}
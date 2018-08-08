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

size_t utf8MatchCodePoint(char* a, char* b) {
    size_t length = utf8Length(*a);
    if (!length) {
        return length;
    }
    for (size_t i = 0; i < length; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return length;
}

bool utf8MatchAtLeast(char* a, char* b, size_t bytes) {
    size_t matchBytes = 0;
    size_t currentMatchLength = 0;
    while ((currentMatchLength = utf8MatchCodePoint(a, b)) != 0 && matchBytes < bytes) {
        matchBytes += currentMatchLength;
        a += currentMatchLength;
        b += currentMatchLength;
    }
    return matchBytes >= bytes;
}


size_t utf8MatchLimit(char* a, char* b, size_t limit) {
    size_t matchBytes = 0;
    size_t currentMatchLength = 0;

    while ((currentMatchLength = utf8MatchCodePoint(a, b)) != 0) {
        size_t newMatchLength = matchBytes + currentMatchLength;
        if (newMatchLength > limit) {
            return matchBytes;
        }
        matchBytes = newMatchLength;
        a += currentMatchLength;
        b += currentMatchLength;
    }
    return matchBytes;
}
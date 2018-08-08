#include "utf8Util.h"



unsigned utf8Length(char initChar) {
    // Invalid 0 byte
    // 0zzzzzzz  1 byte
    // 110yyyyy  2 byte2
    // 1110xxxx  3 bytes
    // 11110www  4 bytes


    if ((initChar & 0x80) == 0) {
        return 1;
    } else if ((initChar & 0xe0) == 0xc0) {
        return 2;
    } else if ((initChar & 0xf0) == 0xe0) {
        return 3;
    } else if ((initChar & 0xf8) == 0xf0) {
        return 4;
    } else {
        return 0;
    }
}
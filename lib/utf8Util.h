
#include <stdbool.h>
#include <stddef.h>

#ifndef LZ4_UTF8_UTF8UTIL_H
#define LZ4_UTF8_UTF8UTIL_H



size_t utf8Length(char initChar);

size_t findMaxUtf8Pos(char* buffer, size_t bufferSize);


#endif //LZ4_UTF8_UTF8UTIL_H

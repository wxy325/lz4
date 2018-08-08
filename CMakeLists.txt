cmake_minimum_required(VERSION 3.7)
project(lz4_utf8)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        lib/lz4.c
        lib/lz4.h
        lib/lz4frame.c
        lib/lz4frame.h
        lib/lz4frame_static.h
        lib/lz4hc.c
        lib/lz4hc.h
        lib/xxhash.c
        lib/xxhash.h
        programs/bench.c
        programs/bench.h
        programs/datagen.c
        programs/datagen.h
        programs/lz4cli.c
        programs/lz4io.c
        programs/lz4io.h
        programs/platform.h
        programs/util.h lib/utf8Util.h lib/utf8Util.c)

add_executable(lz4_utf8 ${SOURCE_FILES})
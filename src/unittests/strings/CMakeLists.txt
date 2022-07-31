cmake_minimum_required(VERSION 3.18)

add_executable(
    strings_test
    bzero.cc
    memchr.cc
    memcmp.cc
    memcpy.cc
    memmove.cc
    memset.cc
    split.cc
    strchr.cc
    strdup.cc
    striteri.cc
    strjoin.cc
    strlcat_real.c
    strlcat.cc
    strlen.cc
    strmapi.cc
    strncmp.cc
    strnstr.cc
    strrchr.cc
    strtrim.cc
    substr.cc
)
target_link_libraries(
    strings_test
    ft
    fakeft
    malloc_pain
    GTest::gtest_main
)

gtest_discover_tests(strings_test)

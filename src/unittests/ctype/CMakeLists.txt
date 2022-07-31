cmake_minimum_required(VERSION 3.18)

add_executable(
    ctype_test
    isalnum.cc
    isalpha.cc
    isascii.cc
    isdigit.cc
    isprint.cc
    tolower.cc
    toupper.cc
)
target_link_libraries(
    ctype_test
    ft
    fakeft
    GTest::gtest_main
)

gtest_discover_tests(ctype_test)

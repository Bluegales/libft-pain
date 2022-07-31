cmake_minimum_required(VERSION 3.18)

add_executable(
    stdlib_test
    atoi.cc
    calloc.cc
    itoa.cc
)
target_link_libraries(
    stdlib_test
    ft
    fakeft
    malloc_pain
    GTest::gtest_main
)

gtest_discover_tests(stdlib_test)

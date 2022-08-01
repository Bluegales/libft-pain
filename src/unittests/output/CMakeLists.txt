cmake_minimum_required(VERSION 3.18)

add_executable(
    output_test
    putchar_fd.cc
    putendl_fd.cc
    putnbr_fd.cc
    putstr_fd.cc
)
target_link_libraries(
    output_test
    ft
    fakeft
    malloc_pain
    GTest::gtest_main
)

gtest_discover_tests(output_test)

cmake_minimum_required(VERSION 3.23)

add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer -fno-common)
link_libraries(-fsanitize=address,undefined)

add_executable(
    ctype
    ctype.cc
)
add_test(
    NAME ctype_test
    COMMAND ctype
)
target_link_libraries(
    ctype
    ft
    fakeft
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ctype)


cmake_minimum_required(VERSION 3.18)

add_executable(
    linked_list_test
    lst_clear.cc
    lstadd_back.cc
    lstadd_front.cc
    lstdelone.cc
    lstiter.cc
    lstlast.cc
    lstmap.cc
    lstnew.cc
    lstsize.cc
    test_list.cc
)
target_link_libraries(
    linked_list_test
    ft
    fakeft
    GTest::gtest_main
)

gtest_discover_tests(linked_list_test)

cmake_minimum_required(VERSION 3.20)

# add_compile_options(-fsanitize=leak,address,undefined -fno-omit-frame-pointer -fno-common -O1)
# add_compile_options(-fsanitize=address -DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address")
add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer -fno-common -O1)
link_libraries(-fsanitize=address,undefined)

include_directories(${LIBFT_FOLDER})
include(GoogleTest)

set(name "isalnum")

function(ctypetest name)
    add_executable(
        ${name}
        ${name}.cc
    )
    add_test(
        NAME ${name}_test
        COMMAND ${name}
    )
    target_link_libraries(
        ${name}
        ft
        GTest::gtest_main
    )
    gtest_discover_tests(${name})
endfunction()

# ctypetest(isalnum)
ctypetest(isalpha)
# ctypetest(isascii)
# ctypetest(isdigit)
# ctypetest(isprint)
# ctypetest(tolower)
# ctypetest(toupper)

cmake_minimum_required(VERSION 3.23)
project(libft_pain)

macro (install)
endmacro ()

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

## search for libft
find_path(
    LIBFT_FOLDER
    NAMES libft
    HINTS ./ ../
)
if(NOT LIBFT_FOLDER)
    message(FATAL_ERROR "Can not find libft folder")
endif()

file(GLOB ft_SRC
     ${LIBFT_FOLDER}/libft/*.c
     ${LIBFT_FOLDER}/libft/*.h
)
add_library(
    ft STATIC
    ${ft_SRC}
)
# if (CMAKE_C_COMPILER_ID STREQUAL "AppleClang")
#   set(CMAKE_LINK_LIBRARY_USING_weak_library
#       "PATH{-weak_library <LIBRARY>}NAME{LINKER:-weak-l<LIB_ITEM>}"
#   )
#   set(CMAKE_LINK_LIBRARY_USING_weak_library_SUPPORTED TRUE)
# endif()
add_library(
    fakeft SHARED
    fakeft/libft.cc
    fakeft/libft.h
)

enable_testing()

add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer -fno-common -O1)
link_libraries(-fsanitize=address,undefined)

include_directories(.)

add_subdirectory(tests)

# Test the makefile potentially
find_file(
    LIBFT_MAKEFILE
    NAMES makefile Makefile
    HINTS LIBFT_FOLDER
)
if(NOT LIBFT_MAKEFILE)
    message(WARNING "Can not find a makefile will build directly from source")
endif()




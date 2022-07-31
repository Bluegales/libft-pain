cmake_minimum_required(VERSION 3.18)
project(libft_pain)

macro (install)
endmacro ()

enable_testing()
set(CMAKE_CXX_STANDARD 17)
include_directories(.)

# =============
# GTEST
# =============

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# =============
# LIBFT
# =============
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
    src/malloc_pain/malloc_pain.cc
)
target_compile_definitions(ft PRIVATE malloc=malloc_pain free=free_pain)

# =============
# MAKEFILE
# =============

# Test the makefile potentially
# find_file(
#     LIBFT_MAKEFILE
#     NAMES makefile Makefile
#     HINTS LIBFT_FOLDER
# )
# if(NOT LIBFT_MAKEFILE)
#     message(WARNING "Can not find a makefile will build directly from source")
# endif()

# =============
# TESTS
# =============

add_subdirectory(src)

cmake_minimum_required(VERSION 3.18)

add_library(
  malloc_pain STATIC
  malloc_pain/malloc_pain.cc
  malloc_pain/malloc_pain.h
)

add_library(
  fakeft SHARED
  fakeft/libft.cc
  fakeft/libft.h
)

add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer -fno-common -O3)
link_libraries(-fsanitize=address,undefined)

add_subdirectory(unittests)

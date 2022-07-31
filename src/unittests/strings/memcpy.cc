// Copyright 2022
// Author: pfuchs

#include <string.h>

#include <algorithm>
#include <vector>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

static void compare(const void* src, size_t n) {
  std::vector<char> real_dst(n + 4);
  std::fill(real_dst.begin(), real_dst.end(), 42);
  std::vector<char> test_dst(real_dst);

  memcpy(real_dst.data() + 2, src, n);
  void* return_ptr = ft_memcpy(test_dst.data() + 2, src, n);
  EXPECT_EQ(test_dst.data() + 2, return_ptr) << "wrong return";
  EXPECT_EQ(real_dst, test_dst);
}

TEST(Memcpy, Length0) {
  compare("aa", 0);
  compare("", 0);
}

TEST(Memcpy, Length1) {
  compare("a", 1);
  compare("", 1);
  compare("Z", 1);
}

TEST(Memcpy, Length10) {
  compare("abcdefghij", 10);
  compare("1234567890", 10);
  compare("qwertyuiop", 10);
  compare("aaaaaaaaaa", 10);
  compare("yyyyyyyyy", 10);
}

TEST(Memcpy, WithNull) {
  compare("\000\001\000\377", 5);
  compare("", 1);
}

// Copyright 2022
// Author: pfuchs

#include <string.h>

#include <algorithm>
#include <vector>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

static void compare(int c, size_t n) {
  std::vector<char> real_dst(n + 4);
  std::fill(real_dst.begin(), real_dst.end(), 42);
  std::vector<char> test_dst(real_dst);

  memset(real_dst.data() + 2, c, n);
  ft_memset(test_dst.data() + 2, c, n);
  EXPECT_EQ(real_dst, test_dst);
}

TEST(Memset, Length0) {
  compare(0, 0);
  compare(1, 0);
}

TEST(Memset, Length1) {
  compare(0, 1);
  compare(1, 1);
}

TEST(Memset, Length10) {
  compare(0, 10);
  compare(1, 10);
  compare(20, 10);
}

TEST(Memset, CharOverflow) {
  compare(200, 5);
  compare(300, 6);
  compare(400, 7);
  compare(INT32_MAX, 5);
  compare(INT32_MIN, 6);
}

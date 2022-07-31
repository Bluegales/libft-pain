// Copyright 2022
// Author: pfuchs

#include <string.h>

#include <algorithm>
#include <vector>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

static void compare(size_t n) {
  std::vector<char> real_dst(n + 4);
  std::fill(real_dst.begin(), real_dst.end(), 42);
  std::vector<char> test_dst(real_dst);

  memset(real_dst.data() + 2, 0, n);
  ft_bzero(test_dst.data() + 2, n);
  EXPECT_EQ(real_dst, test_dst);
}

TEST(Bzero, Length0) { compare(0); }

TEST(Bzero, Length1) { compare(1); }

TEST(Bzero, Length10) { compare(10); }

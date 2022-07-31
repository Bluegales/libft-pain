// Copyright 2022
// Author: pfuchs

#include <ctype.h>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

TEST(Isascii, PositiveChar) {
  for (int i = 0; i <= INT8_MAX; i++) {
    EXPECT_TRUE(ft_isascii(i));
  }
}

TEST(Isascii, NegativeChar) {
  for (int i = -1; i >= INT8_MIN; i--) {
    EXPECT_FALSE(ft_isascii(i));
  }
}

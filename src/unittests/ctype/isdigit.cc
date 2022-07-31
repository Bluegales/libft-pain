// Copyright 2022
// Author: pfuchs

#include <ctype.h>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

TEST(Isdigit, Digits) {
  for (int i = '0'; i <= '9'; i++) {
    EXPECT_TRUE(ft_isdigit(i));
  }
}

TEST(Isdigit, OtherAscii) {
  for (int i = 0; i <= INT8_MAX; i++) {
    if (isdigit(i) == false) {
      EXPECT_FALSE(ft_isdigit(i));
    }
  }
}

TEST(Isdigit, NegativeChar) {
  for (int i = 0; i >= INT8_MIN; i--) {
    EXPECT_FALSE(ft_isdigit(i));
  }
}

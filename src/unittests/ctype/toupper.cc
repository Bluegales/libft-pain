// Copyright 2022
// Author: pfuchs

#include <ctype.h>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

TEST(Toupper, Lowercase) {
  for (int i = 'a'; i <= 'z'; i++) {
    EXPECT_EQ(i - 'a' + 'A', ft_toupper(i));
  }
}

TEST(Toupper, uppercase) {
  for (int i = 'A'; i <= 'Z'; i++) {
    EXPECT_EQ(i, ft_toupper(i));
  }
}

TEST(Toupper, OtherAscii) {
  for (int i = 0; i <= INT8_MAX; i++) {
    if (!isalpha(i))
      EXPECT_EQ(i, ft_toupper(i));
  }
}

TEST(Toupper, NegativeChar) {
  for (int i = -1; i >= INT8_MIN; i--) {
    EXPECT_EQ(i, ft_toupper(i));
  }
}

// Copyright 2022
// Author: pfuchs

#include <ctype.h>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

TEST(Tolower, Lowercase) {
  for (int i = 'a'; i <= 'z'; i++) {
    EXPECT_EQ(i, ft_tolower(i));
  }
}

TEST(Tolower, Uppercase) {
  for (int i = 'A'; i <= 'Z'; i++) {
    EXPECT_EQ(i - 'A' + 'a', ft_tolower(i));
  }
}

TEST(Tolower, OtherAscii) {
  for (int i = 0; i <= INT8_MAX; i++) {
    if (!isalpha(i))
      EXPECT_EQ(i, ft_tolower(i));
  }
}

TEST(Tolower, NegativeChar) {
  for (int i = -1; i >= INT8_MIN; i--) {
    EXPECT_EQ(i, ft_tolower(i));
  }
}

// Copyright 2022
// Author: pfuchs

#include <ctype.h>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

TEST(Isalpha, Lowercase) {
  for (int i = 'a'; i <= 'z'; i++) {
    EXPECT_TRUE(ft_isalpha(i));
  }
}

TEST(Isalpha, Uppercase) {
  for (int i = 'A'; i <= 'Z'; i++) {
    EXPECT_TRUE(ft_isalpha(i));
  }
}

TEST(Isalpha, OtherAscii) {
  for (int i = 0; i <= INT8_MAX; i++) {
    if (isalpha(i) == false) {
      EXPECT_FALSE(ft_isalpha(i));
    }
  }
}

TEST(Isalpha, NegativeChar) {
  for (int i = 0; i >= INT8_MIN; i--) {
    EXPECT_FALSE(ft_isalpha(i));
  }
}

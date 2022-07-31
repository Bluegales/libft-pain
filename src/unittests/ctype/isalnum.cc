// Copyright 2022
// Author: pfuchs

#include <ctype.h>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

TEST(Isalnum, Lowercase) {
  for (int i = 'a'; i <= 'z'; i++) {
    EXPECT_TRUE(ft_isalnum(i));
  }
}

TEST(Isalnum, Uppercase) {
  for (int i = 'A'; i <= 'Z'; i++) {
    EXPECT_TRUE(ft_isalnum(i));
  }
}

TEST(Isalnum, Digits) {
  for (int i = '0'; i <= '9'; i++) {
    EXPECT_TRUE(ft_isalnum(i));
  }
}

TEST(Isalnum, OtherAscii) {
  for (int i = 0; i <= INT8_MAX; i++) {
    if (isalnum(i) == false) {
      EXPECT_FALSE(ft_isalnum(i));
    }
  }
}

TEST(Isalnum, NegativeChar) {
  for (int i = -1; i >= INT8_MIN; i--) {
    EXPECT_FALSE(ft_isalnum(i));
  }
}

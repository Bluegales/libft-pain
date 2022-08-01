// Copyright 2022
// Author: pfuchs

#include <ctype.h>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

TEST(Isprint, Printable) {
  for (int i = 0; i < INT8_MAX; i++) {
    if (isprint(i))
      EXPECT_TRUE(ft_isprint(i));
  }
}

TEST(Isprint, NonPrintableAscii) {
  for (int i = 0; i <= INT8_MAX; i++) {
    if (!isprint(i))
      EXPECT_FALSE(ft_isprint(i));
  }
}

TEST(Isprint, NegativeChar) {
  for (int i = -1; i >= INT8_MIN; i--) {
    EXPECT_FALSE(ft_isprint(i));
  }
}

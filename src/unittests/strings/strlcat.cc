// Copyright 2022
// Author: pfuchs

#include <string.h>

#include <string>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

extern "C" {
  size_t strlcat(char *dst, const char *src, size_t siz);
}

static void compare(const std::string& dest, const std::string& src, size_t n) {
  std::string test_result(dest);
  test_result.resize(dest.length() + n);
  std::string real_result(test_result);
  size_t test_return = ft_strlcat(test_result.data(), src.data(), n);
  size_t real_return = strlcat(real_result.data(), src.data(), n);
  EXPECT_EQ(test_return, real_return);
  EXPECT_EQ(test_result, real_result);
}

TEST(Strlcat, DstSrcEmpty) {
  compare("", "", 0);
  compare("", "", 1);
  compare("", "", 10);
}

TEST(Strlcat, DstEmpty) {
  compare("", "abc", 0);
  compare("", "abc", 1);
  compare("", "abc", 2);
  compare("", "abc", 3);
  compare("", "abc", 4);
  compare("", "abc", 5);
}

TEST(Strlcat, SrcEmpty) {
  compare("abc", "", 0);
  compare("abc", "", 1);
  compare("abc", "", 2);
  compare("abc", "", 3);
  compare("abc", "", 4);
  compare("abc", "", 5);
}

TEST(Strlcat, EnoughSpace) {
  compare("abc", "qwe", 10);
  compare("1234567890", "1234567890", 40);
  compare("qwertyuiop", "1234567890", 40);
}

TEST(Strlcat, NotEnoughSpace) {
  compare("abcd", "e", 5);
  compare("abc", "qw", 5);
  compare("abc", "qwe", 5);
  compare("abc", "1234567890", 5);
}

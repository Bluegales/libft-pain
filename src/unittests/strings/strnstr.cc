// Copyright 2022
// Author: pfuchs

#include <string.h>

#include <string>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

static void compare(const std::string &hay, const std::string &needle,
                    size_t n) {
  size_t found = hay.find(needle);
  if (found == std::string::npos || found + needle.length() > n) {
    EXPECT_EQ(nullptr, ft_strnstr(hay.c_str(), needle.c_str(), n));
  } else {
    EXPECT_EQ(found, ft_strnstr(hay.c_str(), needle.c_str(), n) - hay.c_str());
  }
}

TEST(Strnstr, EmptyStrings) {
  compare("", "", 0);
  compare("", "", INT32_MAX);
}

TEST(Strnstr, NotFound) {
  compare("1234567890", "qwe", 5);
  compare("1234567890", "asd", INT32_MAX);
}

TEST(Strnstr, SizeToShort) {
  compare("1234567890", "12345", 4);
  compare("1234567890", "90", 11);
}

TEST(Strnstr, PartiallyFound) {
  compare("123 1234 12345 123456", "12345", INT32_MAX);
  compare("123 1234", "1234", 11);
}

TEST(Strnstr, JustInRange) {
  compare("1234", "123", 3);
  compare("1234", "34", 4);
}

TEST(Strnstr, SplitNeedle) {
  compare("12 34", "1234", 20);
  compare("12qweqwe34", "124", 12);
}

TEST(Strnstr, EmptyNeedle) {
  compare("12 34", "", 0);
  compare("12qweqwe34", "", 12);
}

TEST(Strnstr, EmptyHay) {
  compare("", "12", 0);
  compare("", "123", 12);
}

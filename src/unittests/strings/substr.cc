// Copyright 2022
// Author: pfuchs

#include <string.h>

#include <string>

#include "gtest/gtest.h"
#include "src/malloc_pain/malloc_pain.h"
#include "src/unittests/libft.h"

class Substr : public ::testing::Test {
 protected:
  void SetUp() override { malloc_size = INT32_MAX; }
  void TearDown() override {
    if (is_leaking()) FAIL() << show_leaked_memory();
  }
};

static void compare(const std::string& s, size_t start, size_t length) {
  std::string real_substr = s.substr(start, length);
  char* result = ft_substr(s.c_str(), start, length);
  std::string test_substr(result);
  EXPECT_EQ(real_substr, test_substr);
  free_pain(result);
}

TEST_F(Substr, EmptyString) {
  compare("", 0, 0);
  compare("", 0, 2);
}

TEST_F(Substr, FullString) {
  compare("12345678901234567890", 0, 21);
  compare("abc", 0, 3);
}

TEST_F(Substr, CutFront) {
  compare("12345678901234567890", 3, 18);
  compare("abc", 1, 2);
}

TEST_F(Substr, CutBack) {
  compare("12345678901234567890", 0, 18);
  compare("abc", 0, 2);
}

TEST_F(Substr, CutBoth) {
  compare("12345678901234567890", 3, 5);
  compare("abc", 1, 1);
}

TEST_F(Substr, ZeroLength) {
  compare("12345678901234567890", 3, 0);
  compare("abc", 1, 0);
}

TEST_F(Substr, MaxLength) {
  compare("12345678901234567890\0001234", 3, SIZE_MAX);
  compare("abc", 1, SIZE_MAX);
}

TEST_F(Substr, StartIsEnd) {
  compare("123", 3, SIZE_MAX);
  compare("1", 1, SIZE_MAX);
}

TEST_F(Substr, MallocFail) {
  malloc_size = 0;
  EXPECT_TRUE(nullptr == ft_substr("a", 0, 2));
}

// Copyright 2022
// Author: pfuchs

#include <string.h>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"
#include "src/malloc_pain/malloc_pain.h"

class Strdup : public ::testing::Test {
 protected:
  void SetUp() override { malloc_size = INT32_MAX; }
  void TearDown() override {
    if (is_leaking()) FAIL() << show_leaked_memory();
  }
};

static void compare(const char *s) {
  char *result = strdup(s);
  for (int i = 0; i < strlen(s) + 1; i++) {
    EXPECT_EQ(s[i], result[i]);
  }
  free_pain(result);
}

TEST_F(Strdup, EmptyString) { compare(""); }

TEST_F(Strdup, Length10) { compare("abcdefghij"); }

TEST_F(Strdup, SpecialCharacters) { compare("\001\002\0377\0376"); }

TEST_F(Strdup, MallocFail) {
  malloc_size = 0;
  EXPECT_TRUE(nullptr == ft_strdup("a"));
}

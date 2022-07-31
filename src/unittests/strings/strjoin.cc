// Copyright 2022
// Author: pfuchs

#include <string.h>

#include <string>

#include "gtest/gtest.h"
#include "src/malloc_pain/malloc_pain.h"
#include "src/unittests/libft.h"

class Strjoin : public ::testing::Test {
 protected:
  void SetUp() override { malloc_size = INT32_MAX; }
  void TearDown() override {
    if (is_leaking()) FAIL() << show_leaked_memory();
  }
};

static void compare(const std::string& s1, const std::string& s2) {
  char* result = ft_strjoin(s1.c_str(), s2.c_str());
  std::string test_result(result);
  std::string real_result(s1);
  real_result.append(s2);
  EXPECT_EQ(test_result, real_result);
  free_pain(result);
}

TEST_F(Strjoin, EmptyStrings) { compare("", ""); }

TEST_F(Strjoin, FirstEmpty) { compare("", "abc"); }

TEST_F(Strjoin, SecondEmpty) { compare("abc", ""); }

TEST_F(Strjoin, Length1) { compare("1", "2"); }

TEST_F(Strjoin, Length10) { compare("abcdefghij", "1234567890"); }

TEST_F(Strjoin, OneLength0) {
  compare("abcdefghij", "0");
  compare("", "1234567890");
}

TEST_F(Strjoin, SpecialCharacters) {
  compare("\001\002\0377\0376", "\002\300");
}

TEST_F(Strjoin, MallocFail) {
  malloc_size = 0;
  EXPECT_TRUE(nullptr == ft_strjoin("a", "b"));
}

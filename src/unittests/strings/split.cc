// Copyright 2022
// Author: pfuchs

#include <string.h>

#include <sstream>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "src/malloc_pain/malloc_pain.h"
#include "src/unittests/libft.h"

class Split : public ::testing::Test {
 protected:
  void SetUp() override { malloc_size = INT32_MAX; }
  void TearDown() override {
    if (is_leaking()) FAIL() << show_leaked_memory();
  }
};

static void compare(const std::string s, char delim) {
  std::vector<std::string> real_split;
  std::stringstream ss(s);
  while (ss.eof() == false) {
    std::string token;
    getline(ss, token, delim);
    if (token.length() != 0) real_split.push_back(token);
  }
  char **result = ft_split(s.c_str(), delim);
  std::vector<std::string> test_split;
  for (auto it = result; *it != NULL; it++) {
    test_split.emplace_back(*it);
    free_pain(*it);
  }
  free_pain(result);
  EXPECT_EQ(real_split, test_split);
}

TEST_F(Split, EmptyString) {
  compare("", 0);
  compare("", 1);
}

TEST_F(Split, NoSplit) {
  compare("1234567890", 'm');
  compare("123", 'a');
}

TEST_F(Split, NullDelim) {
  compare("1234567890", 0);
  compare("123", 0);
}

TEST_F(Split, LeadingSplit) {
  compare("1234567890", '1');
  compare("123", '1');
}

TEST_F(Split, TrailingSplit) {
  compare("1234567890", '0');
  compare("123", '3');
}

TEST_F(Split, LeadingTrailingSplit) {
  compare("01234567890", '0');
  compare("3123", '3');
}

TEST_F(Split, SplitMiddle) {
  compare("01234567890", '4');
  compare("3123", '2');
}

TEST_F(Split, NothingRemaining) {
  compare("111111111", '1');
  compare("2", '2');
}

TEST_F(Split, MultipleSplits) {
  compare("   000  00  00 12  123  ", ' ');
  compare(" 0 0 0 0 0 0 0 0 0 ", ' ');
}

TEST_F(Split, MallocFullFail) {
  malloc_size = 0;
  EXPECT_EQ(nullptr, ft_split("abc", 1));
}

TEST_F(Split, MallocFirstSubstringFail) {
  malloc_size = 20;
  EXPECT_EQ(nullptr, ft_split("123456789012345678901234567890", 1));
}

TEST_F(Split, MallocMiddleSubstringFail) {
  malloc_size = 40;
  EXPECT_EQ(nullptr,
            ft_split("a 1234567890123456789012345678901234567890d", ' '));
}

// Copyright 2022
// Author: pfuchs

#include <string.h>

#include <string>

#include "gtest/gtest.h"
#include "src/malloc_pain/malloc_pain.h"
#include "src/unittests/libft.h"

class Strtrim : public ::testing::Test {
 protected:
  void SetUp() override { malloc_size = INT32_MAX; }
  void TearDown() override {
    if (is_leaking()) FAIL() << show_leaked_memory();
  }
};

std::string trim(const std::string& s, const std::string spaces) {
  size_t start = s.find_first_not_of(spaces);
  size_t end = s.find_last_not_of(spaces);
  return (start == std::string::npos) ? "" : s.substr(start, end - start + 1);
}

static void compare(const std::string& s, const std::string& spaces) {
  std::string real_trim = trim(s, spaces);
  char* result = ft_strtrim(s.c_str(), spaces.c_str());
  std::string test_trim(result);
  EXPECT_EQ(real_trim, test_trim);
  free_pain(result);
}

TEST_F(Strtrim, BothEmpty) {
  compare("", "");
}

TEST_F(Strtrim, StringEmpty) {
  compare("", "asdqwe");
}

TEST_F(Strtrim, DelimEmpty) {
  compare("qweasd", "");
}

TEST_F(Strtrim, NoTrim) {
  compare("aaaaaaaaa", "b");
  compare("aaaaaaaaa", "c");
}

TEST_F(Strtrim, TrimLeft) {
  compare("abc", "a");
  compare("aabc", "a");
}

TEST_F(Strtrim, TrimRight) {
  compare("abc", "c");
  compare("abcc", "c");
}

TEST_F(Strtrim, TrimMulti) {
  compare("01 2 10", "101");
  compare("0010 2 0010", "00001");
}

TEST_F(Strtrim, NoTrimMiddle) {
  compare(" aaaaaaaabbcaaa ", "a");
  compare("0asdasdoaosd0", "asdasdoaosd");
}

TEST_F(Strtrim, FullTrim) {
  compare("aabbaa", "ab");
  compare("a", "a");
}

TEST_F(Strtrim, MallocFail) {
  malloc_size = 0;
  EXPECT_TRUE(nullptr == ft_strtrim("a", " "));
}

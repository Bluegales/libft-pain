// Copyright 2022
// Author: pfuchs

#include <string.h>

#include <string>

#include "gtest/gtest.h"
#include "src/malloc_pain/malloc_pain.h"
#include "src/unittests/libft.h"

class Strmapi : public ::testing::Test {
 protected:
  void SetUp() override { malloc_size = INT32_MAX; }
  void TearDown() override {
    if (is_leaking()) FAIL() << show_leaked_memory();
  }
};

static void compare(const std::string& s, char (*func)(unsigned int, char)) {
  std::string real_map(s);
  for (int i = 0; i < real_map.length(); i++) {
    real_map[i] = func(i, real_map[i]);
  }
  char* result = ft_strmapi(s.c_str(), func);
  std::string test_map(result, s.length());
  EXPECT_EQ(real_map, test_map);
  free_pain(result);
}

static char increment(unsigned int i, char c) { return (c + i) ? (c + i) : 1; }

static char zero(unsigned int i, char c) { return (0); }

TEST_F(Strmapi, EmptyString) {
  compare("", increment);
  compare("", zero);
}

TEST_F(Strmapi, Increment) { compare("1234567890", increment); }

TEST_F(Strmapi, ZeroString) { compare("1234567890", zero); }

TEST_F(Strmapi, MallocFail) {
  malloc_size = 0;
  EXPECT_TRUE(nullptr == ft_strmapi("a", increment));
}

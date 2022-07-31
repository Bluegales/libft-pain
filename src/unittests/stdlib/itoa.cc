// Copyright 2022
// Author: pfuchs

#include <string>

#include "gtest/gtest.h"
#include "src/malloc_pain/malloc_pain.h"
#include "src/unittests/libft.h"

class Itoa : public ::testing::Test {
 protected:
  void SetUp() override { malloc_size = INT32_MAX; }
  void TearDown() override {
    if (is_leaking()) FAIL() << show_leaked_memory();
  }
};

static void compare(int n) {
  char *result = ft_itoa(n);
  std::string test_result(result);
  EXPECT_EQ(test_result, std::to_string(n));
  free_pain(result);
}

TEST_F(Itoa, Null) {
  compare(0);
}

TEST_F(Itoa, PositiveSingleDigit) {
  compare(5);
}

TEST_F(Itoa, NegativeSingleDigit) {
  compare(-5);
}

TEST_F(Itoa, Positive) {
  compare(42);
  compare(420);
  compare(1337);
}

TEST_F(Itoa, Negative) {
  compare(-42);
  compare(-420);
  compare(-1337);
}

TEST_F(Itoa, IntMax) {
  compare(INT32_MAX);
}

TEST_F(Itoa, IntMin) {
  compare(INT32_MIN);
}

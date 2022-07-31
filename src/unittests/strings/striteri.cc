// Copyright 2022
// Author: pfuchs

#include <string.h>

#include <string>

#include "gtest/gtest.h"
#include "src/malloc_pain/malloc_pain.h"
#include "src/unittests/libft.h"

static void compare(const std::string &s, void (*func)(unsigned int, char *)) {
  std::string real_iteri(s);
  for (int i = 0; i < real_iteri.length(); i++) {
    func(i, &(real_iteri[i]));
  }
  std::string test_iteri(s);
  ft_striteri(test_iteri.data(), func);
  EXPECT_EQ(real_iteri, test_iteri);
}

static void increment(unsigned int i, char *c) { *c = (*c + i) ? (*c + i) : 1; }

static void zero(unsigned int i, char *c) { *c = 0; }

TEST(Striteri, EmptyString) {
  compare("", increment);
  compare("", zero);
}

TEST(Striteri, Increment) { compare("1234567890", increment); }

TEST(Striteri, ZeroString) { compare("1234567890", zero); }

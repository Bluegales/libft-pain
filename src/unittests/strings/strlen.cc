// Copyright 2022
// Author: pfuchs

#include <string.h>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

static void compare(const char *s) { EXPECT_EQ(strlen(s), ft_strlen(s)); }

TEST(Strlen, EmptyString) { compare(""); }

TEST(Strlen, Length10) { compare("abcdefghij"); }

TEST(Strlen, SpecialCharacters) { compare("\001\002\0377\0376"); }

// Copyright 2022
// Author: pfuchs

#include <stdlib.h>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

TEST(atoi, Empty) {
    vs_real("");
}

TEST(atoi, Zero) {
    vs_real("0");
}

TEST(atoi, SimplePositive) {
    vs_real("1");
    vs_real("42");
    vs_real("1337");
    vs_real("1337");
}

TEST(atoi, SimpleNegatives) {
    vs_real("-1");
    vs_real("-42");
    vs_real("-1337");
    vs_real("-1337");
}

TEST(atoi, LeadingZeros) {
    vs_real("01");
    vs_real("001");
    vs_real("0000000009");
    vs_real("-0000000999");
}

TEST(atoi, InvalidSigns) {
    vs_real("--9");
    vs_real("-+9");
    vs_real("+-9");
    vs_real("++9");
}

TEST(atoi, LeadingWhitespaces) {
    vs_real(" 42");
    vs_real("                 42");
    vs_real("  \n    \t   \n   \t-42");
}

TEST(atoi, InvalidCharacters) {
    vs_real("a42");
    vs_real("\00142");
    vs_real("a");
    vs_real("-a2");
    vs_real("+a2");
    vs_real("-a");
    vs_real("+a");
    vs_real("asdfghjklqwertyuiopqwertyuiop");
}

TEST(atoi, CharactersInNumber) {
    vs_real("123a42");
    vs_real("123 42");
    vs_real("123-42");
    vs_real("123+42");
    vs_real("123this");
    vs_real("0this123");
    vs_real("-123+42");
    vs_real("-123this");
    vs_real("-0this123");
    vs_real("-this123+42");
    vs_real("-this123this");
    vs_real("-this0this123");
}

TEST(atoi, IntMax) {
    vs_real("2147483647");
    vs_real("2147483647 ");
}

TEST(atoi, IntMin) {
    vs_real("-2147483648");
    vs_real("-2147483648 ");
}


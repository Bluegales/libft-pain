/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctypes.cc                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:50:12 by pfuchs            #+#    #+#             */
/*   Updated: 2022/07/26 05:22:33 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <functional>

#include <gtest/gtest.h>

#include "fakeft/libft.h"

void test_char_range(std::function<int(int)> real, std::function<int(int)> ft) {
  ASSERT_NO_FATAL_FAILURE(ft(0));
  for (int i = 0; i < 256; i++) {
    EXPECT_EQ(real(i), ft(i));
  }
}

TEST(isalnum, CharRange) {
  test_char_range(isalnum, ft_isalnum);
}

TEST(isalpha, CharRange) {
  test_char_range(isalpha, ft_isalpha);
}

TEST(isascii, CharRange) {
  test_char_range(isascii, ft_isascii);
}

TEST(isdigit, CharRange) {
  test_char_range(isdigit, ft_isdigit);
}

TEST(isprint, CharRange) {
  test_char_range(isprint, ft_isprint);
}

TEST(tolower, CharRange) {
  test_char_range(tolower, ft_tolower);
}

TEST(toupper, CharRange) {
  test_char_range(toupper, ft_toupper);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:21:51 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 11:28:18 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"
#include "btest.h"

const char	g_test0[] = "";
const char	g_test1[] = "0";
const char	g_test2[] = "01";
const char	g_test3[] = "012";
const char	g_test4[] = "01012";
const char	g_test5[] = "0000";

static int	test_empty_needle(void)
{
	int		error;

	error = 0;
	error += btest_pointer(00, g_test0, ft_strnstr(g_test0, "", 0));
	error += btest_pointer(01, g_test0, ft_strnstr(g_test0, "", 1));
	error += btest_pointer(02, g_test1, ft_strnstr(g_test1, "", 0));
	error += btest_pointer(03, g_test1, ft_strnstr(g_test1, "", 1));
	error += btest_pointer(04, g_test2, ft_strnstr(g_test2, "", 10));
	return (error);
}

static int	test_not_found(void)
{
	int		error;

	error = 0;
	error += btest_pointer(10, NULL, ft_strnstr(g_test0, "0", 0));
	error += btest_pointer(11, NULL, ft_strnstr(g_test0, "0", 1));
	error += btest_pointer(12, NULL, ft_strnstr(g_test1, "0", 0));
	error += btest_pointer(13, NULL, ft_strnstr(g_test1, "1", 1));
	error += btest_pointer(14, NULL, ft_strnstr(g_test2, "11", 10));
	error += btest_pointer(15, NULL, ft_strnstr(g_test2, "00", 10));
	error += btest_pointer(16, NULL, ft_strnstr(g_test3, "0123", 10));
	error += btest_pointer(17, NULL, ft_strnstr(g_test3, "012", 2));
	error += btest_pointer(18, NULL, ft_strnstr(g_test3, "12", 2));
	error += btest_pointer(19, NULL, ft_strnstr(g_test5, "00", 1));
	return (error);
}

static int	test_found(void)
{
	int		error;

	error = 0;
	error += btest_pointer(20, g_test0, ft_strnstr(g_test0, "", 0));
	error += btest_pointer(20, g_test0, ft_strnstr(g_test0, "", 1));
	error += btest_pointer(21, g_test1, ft_strnstr(g_test1, "0", 1));
	error += btest_pointer(22, g_test2, ft_strnstr(g_test2, "0", 1));
	error += btest_pointer(23, g_test2, ft_strnstr(g_test2, "01", 2));
	error += btest_pointer(24, g_test2 + 1, ft_strnstr(g_test2, "1", 2));
	error += btest_pointer(25, g_test3, ft_strnstr(g_test3, "012", 3));
	error += btest_pointer(26, g_test3 + 2, ft_strnstr(g_test3, "2", 3));
	error += btest_pointer(27, g_test4, ft_strnstr(g_test4, "01012", 5));
	error += btest_pointer(28, g_test4 + 2, ft_strnstr(g_test4, "012", 5));
	error += btest_pointer(29, g_test4, ft_strnstr(g_test4, "0\0""012", 5));
	error += btest_pointer(210, g_test5, ft_strnstr(g_test5, "00", 4));
	return (error);
}

int	main(void)
{
	int		error;

	error = 0;
	error += test_empty_needle();
	error += test_not_found();
	error += test_found();
	btest_print_result(error);
	return (0);
}

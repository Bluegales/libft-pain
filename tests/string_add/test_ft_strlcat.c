/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:21:51 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/08 12:09:30 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"
#include "btest.h"

const char	g_str1[] = "";
const char	g_str2[] = "ap";
const char	g_str3[] = "0123456";
const char	g_str4[] = "abcdefghi";
const char	g_str5[] = "014\0""99991111";

// size_t	my_strlcat(char *dst, const char *src, size_t siz)
// {
// 	char		*d;
// 	const char	*s;
// 	size_t		n;
// 	size_t		dlen;

// 	d = dst;
// 	s = src;
// 	n = siz;
// 	while (n-- != 0 && *d != '\0')
// 		d++;
// 	dlen = d - dst;
// 	n = siz - dlen;
// 	if (n == 0)
// 		return (dlen + strlen(s));
// 	while (*s != '\0')
// 	{
// 		if (n != 1)
// 		{
// 			*d++ = *s;
// 			n--;
// 		}
// 		s++;
// 	}
// 	*d = '\0';
// 	return (dlen + (s - src));
// }

static int	test_no_termination(void)
{
	int		error;
	int		got_return;
	char	dest[20];
	char	src[20];
	char	original[20];

	error = 0;
	memset(original, 20, 20);
	memset(dest, 20, 20);
	memset(src, 10, 20);
	src[5] = '\0';
	got_return = ft_strlcat(dest, src, 0);
	error += btest_memory(0, original, dest, 20);
	error += btest_int(101, 5, got_return);
	got_return = ft_strlcat(dest, src, 10);
	error += btest_memory(0, original, dest, 20);
	error += btest_int(102, 15, got_return);
	return (error);
}

static int	test_trucation(const char *s1, const char *s2)
{
	int		error;
	int		exp_return;
	int		got_return;
	char	exp[20];
	char	got[20];

	error = 0;
	memset(exp, 20, 20);
	memset(got, 20, 20);
	strcpy(exp, s1);
	strcpy(got, s1);
	got_return = ft_strlcat(got, s2, 10);
	strncat(exp, s2, 10 - strlen(s1) - 1);
	exp_return = strlen(s1) + strlen(s2);
	error += btest_memory(0, exp, got, 20);
	error += btest_int(102, exp_return, got_return);
	return (error);
}

int	main(void)
{
	int		error;

	error = 0;
	error += test_no_termination();
	error += test_trucation(g_str1, g_str1);
	error += test_trucation(g_str1, g_str2);
	error += test_trucation(g_str2, g_str1);
	error += test_trucation(g_str2, g_str2);
	error += test_trucation(g_str3, g_str2);
	error += test_trucation(g_str2, g_str3);
	error += test_trucation(g_str2, g_str4);
	error += test_trucation(g_str3, g_str4);
	error += test_trucation(g_str3, g_str5);
	error += test_trucation(g_str5, g_str3);
	error += test_trucation(g_str4, g_str3);
	btest_print_result(error);
	return (0);
}

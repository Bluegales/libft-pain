/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:21:51 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 11:20:14 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"
#include "btest.h"

const char	g_str1[] = "";
const char	g_str2[] = "a";
const char	g_str3[] = "0123";
const char	g_str4[] = "012423\0""123";

int	test(const char *s1, const char *s2)
{
	int		error;
	char	exp[20];
	char	*got;

	error = 0;
	got = ft_strjoin(s1, s2);
	strcpy(exp, s1);
	strcat(exp, s2);
	error += btest_memory(0, exp, got, strlen(exp) + 1);
	free(got);
	return (error);
}

int	main(void)
{
	int		error;

	error = 0;
	error += test(g_str1, g_str1);
	error += test(g_str1, g_str2);
	error += test(g_str2, g_str1);
	error += test(g_str2, g_str2);
	error += test(g_str3, g_str4);
	error += test(g_str4, g_str3);
	btest_print_result(error);
	return (0);
}

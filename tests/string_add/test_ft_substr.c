/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:21:51 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/08 12:17:31 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"
#include "btest.h"

const char	g_src0[1] = "";
const char	g_src1[10] = "abcdefghi";
const char	g_src2[30] = "abcdefghijklmnopqrstuvwxyz012";

static char	*exp_substr(char const *s, unsigned int start, size_t len)
{
	return (strndup(s + start, len));
}

static int	test_null(void)
{
	int		error;
	int		i;
	char	null_test[500];
	char	*got;

	error = 0;
	i = 0;
	while (i < 500)
	{
		null_test[i] = 'O';
		i++;
	}
	got = ft_substr(null_test, 0, 450);
	error += btest_pointer(01, NULL, got);
	free(got);
	return (error);
}

static int	test(const char *src, int start, int len)
{
	int		error;
	char	*exp;
	char	*got;

	error = 0;
	exp = exp_substr(src, start, len);
	got = ft_substr(src, start, len);
	error += btest_int(0, strlen(exp), strlen(got));
	error += btest_memory(len, exp, got, strlen(exp));
	//free(exp);
	free(got);
	return (error);
}

int	main(void)
{
	int	error;

	error = 0;
	error += test_null();
	error += test(g_src0, 0, 0);
	error += test(g_src1, 0, 5);
	error += test(g_src1, 5, 0);
	error += test(g_src1, 2, 2);
	error += test(g_src1, 9, 0);
	error += test(g_src2, 10, 10);
	btest_print_result(error);
}

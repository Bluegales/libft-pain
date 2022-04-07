/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:31:19 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 11:08:49 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include "libft.h"
#include "btest.h"

const char	g_src0[1] = "";
const char	g_src1[10] = "abcdefghi";
const char	g_src2[30] = "abcdefghijklmnopqrstuvwxyz012";

int	test(const char *src)
{
	int		error;
	char	*exp;
	char	*got;

	error = 0;
	exp = strdup(src);
	got = ft_strdup(src);
	error += btest_int(0, strlen(exp), strlen(got));
	error += btest_memory(1, exp, got, strlen(exp));
	free(exp);
	free(got);
	return (error);
}

int	test_malloc(void)
{
	char	*got;
	char	to_long[420];

	memset(to_long, 'o', 420);
	to_long[420] = '\0';
	got = ft_strdup(to_long);
	return (btest_pointer(420, 0, got));
}

int	main(void)
{
	int	error;

	error = 0;
	error += test(g_src0);
	error += test(g_src1);
	error += test(g_src2);
	error += test_malloc();
	btest_print_result(error);
}

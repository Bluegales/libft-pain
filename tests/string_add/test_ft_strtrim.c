/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:21:51 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 11:29:36 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "btest.h"

const char	g_src0[1] = "";
const char	g_src1[10] = "abcdefghi";
const char	g_src2[30] = "abcdefghijklmnopqrstuvwxyz012";

int	test_null(void)
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
	got = ft_strtrim(null_test, " any");
	error += btest_pointer(01, NULL, got);
	free(got);
	return (error);
}

int	test(void)
{
	int		error;
	char	*got;

	error = 0;
	got = ft_strtrim("simple", "impl");
	error += btest_memory(0, "simple", got, 7);
	free(got);
	got = ft_strtrim("  si mp le  ", "a a");
	error += btest_memory(1, "si mp le", got, 9);
	free(got);
	got = ft_strtrim(" simple f", "adqwf ");
	error += btest_memory(2, "simple", got, 7);
	free(got);
	got = ft_strtrim("simple ", "");
	error += btest_memory(3, "simple ", got, 8);
	free(got);
	return (error);
}

int	main(void)
{
	int	error;

	error = 0;
	error += test_null();
	error += test();
	btest_print_result(error);
}

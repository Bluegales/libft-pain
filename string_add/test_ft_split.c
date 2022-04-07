/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strsplit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:28:52 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 11:28:44 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"
#include "btest.h"

static void	free_splits(char **splits)
{
	char	**it;

	it = splits;
	while (*it)
	{
		free(*it);
		it++;
	}
	free(splits);
}

static int	test_null(void)
{
	int		i;
	int		error;
	char	null_test[900];
	char	**got;

	error = 0;
	i = 0;
	while (i < 899)
	{
		null_test[i] = 'O';
		null_test[i + 1] = '_';
		i += 2;
	}
	null_test[899] = '\0';
	got = ft_split(null_test, '_');
	error += btest_pointer(00, NULL, got);
	free(got);
	null_test[2] = 'P';
	null_test[5] = 'P';
	got = ft_split(null_test, 'P');
	error += btest_pointer(01, NULL, got);
	free(got);
	return (error);
}

static int	test_simple(void)
{
	int		error;
	char	**got;

	error = 0;
	got = ft_split("", '_');
	error += btest_pointer(11, NULL, *got);
	free_splits(got);
	got = ft_split("0", '0');
	error += btest_pointer(12, NULL, *got);
	free_splits(got);
	got = ft_split("000", '0');
	error += btest_pointer(13, NULL, *got);
	free_splits(got);
	got = ft_split("123", '_');
	error += btest_memory(0, "123", *got, 4);
	free_splits(got);
	got = ft_split("___1___", '_');
	error += btest_memory(1, "1", *got, 2);
	free_splits(got);
	return (error);
}

static int	test_string(void)
{
	int		error;
	char	**got;

	error = 0;
	got = ft_split("__0_1__234_", '_');
	error += btest_memory(0, "0", got[0], 2);
	error += btest_memory(1, "1", got[1], 2);
	error += btest_memory(2, "234", got[2], 4);
	error += btest_pointer(2, NULL, got[3]);
	free_splits(got);
	got = ft_split("_0_ 1_ _234_", '\0');
	error += btest_memory(3, "_0_ 1_ _234_", got[0], 13);
	error += btest_pointer(2, NULL, got[1]);
	free_splits(got);
	got = ft_split("42_is a cool place to be", '_');
	error += btest_memory(4, "42", got[0], 3);
	error += btest_memory(5, "is a cool place to be", got[1], 22);
	error += btest_pointer(2, NULL, got[2]);
	free_splits(got);
	return (error);
}

int	main(void)
{
	int	error;

	error = 0;
	error += test_null();
	error += test_simple();
	error += test_string();
	btest_print_result(error);
	return (0);
}

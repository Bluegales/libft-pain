/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctype_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:38:55 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 10:38:57 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btest.h"

static void	ctype_test(int (*expected_func)(int),
	int (*got_func)(int), int bool)
{
	int		i;
	int		error;
	int		extected[256];
	int		got[256];

	error = 0;
	i = 0;
	while (i < 256)
	{
		extected[i] = expected_func(i);
		got[i] = got_func(i);
		if (bool)
		{
			extected[i] = (extected[i] && 1);
			got[i] = (got[i] && 1);
		}
		i++;
	}
	error += btest_memory(0, extected, got, 256);
	btest_print_result(error);
}

void	ctype_test_bool(int (*expected_func)(int), int (*got_func)(int))
{
	ctype_test(expected_func, got_func, 1);
}

void	ctype_test_int(int (*expected_func)(int), int (*got_func)(int))
{
	ctype_test(expected_func, got_func, 0);
}

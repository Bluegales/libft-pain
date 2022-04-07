/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btest_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:47:18 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 08:52:23 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btest_types.h"

#include <stdio.h>

#include "colors.h"

int	btest_int(int id, int expected, int got)
{
	if (expected == got)
		return (0);
	printf(COL_RED"  ERROR on <%d>: expected: <%d> got: <%d>\n"COL_NRM,
		id, expected, got);
	return (1);
}

int	btest_bool(int id, int expected, int got)
{
	if (expected == 0 && got == 0)
		return (0);
	if (expected != 0 && got != 0)
		return (0);
	printf(COL_RED"  ERROR on <%d>: expected: <%d> got: <%d>\n"COL_NRM,
		id, expected, got);
	return (1);
}

int	btest_pointer(int id, const void *expected, const void *got)
{
	if (expected == got)
		return (0);
	printf(COL_RED"  ERROR on <%d>: expected: <%p> got: <%p>\n"COL_NRM,
		id, expected, got);
	return (1);
}

int	btest_memory(int id, const void *expected, const void *got, int size)
{
	int			error;
	int			i;

	error = 0;
	i = 0;
	printf(COL_RED);
	while (i < size)
	{
		if (((const char *)expected)[i] != ((const char *)got)[i])
		{
			if (error < 5)
				printf("    ERROR on byte %d: expected: <%d> got: <%d>\n",
					i, ((const char *)expected)[i], ((const char *)got)[i]);
			error++;
		}
		i++;
	}
	if (error)
	{
		printf("  ERROR on <%d>: %d bytes different\n", id, error);
		return (1);
	}
	printf(COL_NRM);
	return (0);
}

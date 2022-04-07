/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btest_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:42:02 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/14 21:00:47 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btest_result.h"

#include "btest_malloc.h"
#include "colors.h"

#include <stdio.h>

void	btest_print_result(int error)
{
	if (btest_get_leaks())
	{
		printf(COL_RED"  ERROR: Leaked %d\n"COL_NRM, btest_get_leaks());
		error++;
	}
	if (error)
		printf(COL_RED"ERROR count: %d\n"COL_NRM, error);
	if (!error)
		printf(COL_GRN"  OK\n"COL_NRM);
}

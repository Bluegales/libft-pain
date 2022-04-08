/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btest_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:19:38 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/08 12:13:32 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btest_malloc.h"

#include <stdlib.h>

static int		g_allocations = 0;
static size_t	limit = 420;

void	*malloc(size_t size)
{
	int		i;
	char	*memory;

	if (size >= limit)
		return (NULL);
	memory = calloc(1, size);
	if (!memory)
		return (NULL);
	g_allocations++;
	i = 0;
	while (i < (int)size)
	{
		memory[i] = i + 42;
		i++;
	}
	return (memory);
}

void	free(void *ptr)
{
	if (ptr)
		g_allocations--;
}

int	btest_get_leaks(void)
{
	return (g_allocations);
}

void	btest_set_malloc_limit(size_t new_limit)
{
	limit = new_limit;
}

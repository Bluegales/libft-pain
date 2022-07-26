/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 08:47:26 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/22 16:45:29 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_memset

#include <stdlib.h> // malloc
#include <stddef.h> // NULL size_t

// Allocates memory for "num" items with "size", initialises to 0
void	*ft_calloc(size_t num, size_t size)
{
	char	*memory;

	memory = (char *)malloc(num * size);
	if (!memory)
		return (NULL);
	ft_memset(memory, 0, num * size);
	return (memory);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:01:40 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/22 16:45:03 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL size_t

// Sets "n" bytes from "mem" to "c"
void	*ft_memset(void *mem, int c, size_t n)
{
	unsigned char	*dest;

	dest = (unsigned char *)mem;
	while (n)
	{
		*dest = (unsigned char)c;
		dest++;
		n--;
	}
	return (mem);
}

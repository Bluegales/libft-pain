/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:34:36 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/22 15:23:43 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_memcpy

#include <stddef.h> // NULL size_t

// Copies "n" bytes from memory area "src" to memory area "dest"
// memory can overlap
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d < s)
	{
		ft_memcpy(dest, src, n);
		return (dest);
	}
	d += n - 1;
	s += n - 1;
	while (n)
	{
		*d = *s;
		d--;
		s--;
		n--;
	}
	return (dest);
}

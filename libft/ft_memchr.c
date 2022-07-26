/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:04:06 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/22 16:45:07 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL size_t

// Searches "n" bytes in "hay" for "c" returning the first occurence
void	*ft_memchr(const void *hay, int c, size_t n)
{
	unsigned char		*str_hay;
	unsigned char		needle;

	str_hay = (unsigned char *)hay;
	needle = (unsigned char)c;
	while (n)
	{
		if (*str_hay == needle)
			return ((void *)str_hay);
		str_hay++;
		n--;
	}
	return (NULL);
}

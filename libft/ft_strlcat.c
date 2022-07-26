/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 23:22:49 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/22 16:45:23 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_strlen

#include <stddef.h> // NULL size_t

// strncat but null terminates the result unless dest is longer than n
size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	src_length;
	size_t	dst_length;

	src_length = ft_strlen(src);
	dst_length = ft_strlen(dest);
	if (n <= dst_length)
		return (n + src_length);
	dest += dst_length;
	n -= (dst_length + 1);
	while (*src && n)
	{
		*dest = *src;
		src++;
		dest++;
		n--;
	}
	*dest = '\0';
	return (dst_length + src_length);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:11:10 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/22 16:45:05 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL size_t

// Compares "n" bytes in "mem1" with "mem2" returns 0 on match,
// <0 if mem1 has lower value than mem2, >0 if mem1 has higher value than mem2
int	ft_memcmp(const void *mem1, const void *mem2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *)mem1;
	str2 = (const unsigned char *)mem2;
	while (n)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}
	return (0);
}

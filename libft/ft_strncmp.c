/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:51:32 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/22 15:17:12 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL size_t

// Compares the first "n" characters from "str1" with "str2" returns 0 on match,
// <0 if str1 has lower value than str2, >0 if str1 has higher value than str2
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*us1;
	const unsigned char	*us2;

	us1 = (const unsigned char *)s1;
	us2 = (const unsigned char *)s2;
	while (n)
	{
		if (*us1 != *us2)
			return (*us1 - *us2);
		if (*us1 == '\0')
			return (*us1 - *us2);
		us1++;
		us2++;
		n--;
	}
	return (0);
}

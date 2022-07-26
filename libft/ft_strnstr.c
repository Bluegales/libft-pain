/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:14:59 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/22 15:17:19 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL size_t

// Returns the first occurence of "needle" in the first n characters of "hay"
char	*ft_strnstr(const char *hay, const char *needle, size_t n)
{
	const char	*needle_it;
	const char	*hay_it;
	size_t		remaining_length;

	if (*needle == '\0')
		return ((char *)hay);
	while (*hay && n)
	{
		needle_it = needle;
		hay_it = hay;
		remaining_length = n;
		while (*hay_it && *hay_it == *needle_it && remaining_length)
		{
			hay_it++;
			needle_it++;
			remaining_length--;
		}
		if (*needle_it == '\0')
			return ((char *)hay);
		hay++;
		n--;
	}
	return (NULL);
}

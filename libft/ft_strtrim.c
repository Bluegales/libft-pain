/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:01:14 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/22 20:23:15 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_strndup ft_strspn

#include <stdlib.h> // NULL size_t

// returns number of characters in str1 before finding a character not from str2
static size_t	strspn(const char *str1, const char *str2)
{
	const char	*it1;
	const char	*it2;

	it1 = str1;
	while (*it1)
	{
		it2 = str2;
		while (*it1 != *it2 && *it2)
			it2++;
		if (*it2 == '\0')
			return (it1 - str1);
		it1++;
	}
	return (it1 - str1);
}

// returns a freeable copy of "s" trimming chars in set from front and back
char	*ft_strtrim(const char *str, const char *set)
{
	int		length;

	str += strspn(str, set);
	length = 0;
	while (str[length])
		length++;
	while (length > 0 && ft_strchr(set, str[length - 1]))
		length--;
	return (ft_substr(str, 0, length));
}

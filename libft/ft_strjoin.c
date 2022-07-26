/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:00:42 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/09 14:56:37 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_strlen ft_memcpy

#include <stdlib.h> // malloc

// Returns a freeable string which is the concatination of str1 and str2
char	*ft_strjoin(char const *str1, char const *str2)
{
	int		l1;
	int		l2;
	char	*new_str;

	l1 = ft_strlen(str1);
	l2 = ft_strlen(str2);
	new_str = malloc(l1 + l2 + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, str1, l1);
	ft_memcpy(new_str + l1, str2, l2);
	new_str[l1 + l2] = '\0';
	return (new_str);
}

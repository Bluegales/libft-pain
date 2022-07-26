/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:44:59 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/22 16:45:42 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_strlen ft_memcpy

#include <stddef.h> // NULL size_t
#include <stdlib.h> // malloc

// Returns a freeable copy of str
char	*ft_strdup(const char *str)
{
	size_t	length;
	char	*new_str;

	length = ft_strlen(str);
	new_str = (char *)malloc(length + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, str, length + 1);
	return (new_str);
}

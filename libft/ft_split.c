/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:22:40 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/09 11:34:26 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" //ft_strchr

#include <stdlib.h> // malloc free

static int	count_splits(const char *str, const char *delims)
{
	int		splits;
	char	last_seperator;

	splits = 0;
	last_seperator = 1;
	while (*str)
	{
		if (last_seperator && !ft_strchr(delims, *str))
		{
			splits++;
		}
		if (ft_strchr(delims, *str))
			last_seperator = 1;
		else
			last_seperator = 0;
		str++;
	}
	return (splits);
}

// Creates a split at the location of split
// Returns the length of the split created
// Returns -1 if allocation fails
static int	create_split(const char *str, const char *delims, char **split)
{
	int			length;
	const char	*it1;
	const char	*it2;

	it1 = str;
	length = -1;
	while (*it1 && length == -1)
	{
		it2 = delims;
		while (*it2 && length == -1)
		{
			if (*it1 == *it2)
				length = (it1 - str);
			it2++;
		}
		it1++;
	}
	if (length == -1)
		length = (it1 - str);
	*split = (char *)malloc(length + 1);
	if (!*split)
		return (-1);
	ft_strlcpy(*split, str, length + 1);
	return (length);
}

// Loops through the string and creates all the splits
// On error it frees the created strings and returns 1
static int	fill_splits(const char *str, const char *delims, char **splits)
{
	char	last_seperator;
	int		split_length;

	last_seperator = 1;
	while (*str)
	{
		if (last_seperator && !ft_strchr(delims, *str))
		{
			split_length = create_split(str, delims, splits);
			if (split_length == -1)
				return (1);
			str += split_length - 1;
			splits++;
		}
		if (ft_strchr(delims, *str))
			last_seperator = 1;
		else
			last_seperator = 0;
		str++;
	}
	return (0);
}

// Returns a freeable NULL terminated array of freeable strings obtained by
// spliting "str" with "delims".
char	**ft_strsplit(const char *str, const char *delims)
{
	char	**splits;
	char	**it;
	int		count;

	count = count_splits(str, delims);
	splits = (char **)malloc(sizeof(char *) * (count + 1));
	if (!splits)
		return (NULL);
	splits[count] = NULL;
	if (fill_splits(str, delims, splits))
	{
		it = splits;
		while (*it)
		{
			free(*it);
			it++;
		}
		free(splits);
		splits = NULL;
	}
	return (splits);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:02:09 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/22 16:45:30 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_intlen

#include <stdlib.h> // malloc
#include <stddef.h> // NULL size_t

// Returns the length of an integer in string representation
static int	intlen(int n)
{
	int	size;

	size = 0;
	if (n < 0)
		size++;
	if (n > 0)
		n *= -1;
	if (n % 10 == 0)
		n--;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static void	add_digit(int digit, char *array)
{
	if (digit < 0)
	{
		*array = (digit % 10) * -1 + '0';
	}
	else
	{
		*array = (digit % 10) + '0';
	}
}

// Returns a freeable string representing the int n
char	*ft_itoa(int n)
{
	int		digits;
	int		sign;
	char	*str;
	char	*str_end_it;

	digits = intlen(n);
	str = malloc(digits + 1);
	str_end_it = str + digits;
	if (!str)
		return (NULL);
	sign = 0;
	if (n < 0)
		sign = 1;
	*str_end_it = '\0';
	str_end_it--;
	while (str <= str_end_it)
	{
		add_digit(n, str_end_it);
		str_end_it--;
		n /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

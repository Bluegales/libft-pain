/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:10:53 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/09 21:54:23 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

// Adds a signle digit as its character representaion to the array
static void	add_digit(int digit, char *array)
{
	if (digit % 10 < 0)
	{
		*array = (digit % 10) * -1 + '0';
	}
	else
	{
		*array = (digit % 10) + '0';
	}
}

// Outputs the integer n to the file descriptor fd.
void	ft_putnbr_fd(int n, int fd)
{
	char	buffer[12];
	int		sign;
	int		i;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	sign = 0;
	if (n < 0)
		sign = 1;
	i = 12;
	while (n != 0)
	{
		i--;
		add_digit(n % 10, buffer + i);
		n /= 10;
	}
	if (sign)
	{
		i--;
		buffer[i] = '-';
	}
	write(fd, buffer + i, 12 - i);
}

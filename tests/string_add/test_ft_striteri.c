/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:21:51 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 11:19:10 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"
#include "btest.h"

static void	increment(unsigned int i, char *c)
{
	*c = *c + i;
	if (*c == '\0')
		*c = 1;
}

static void	zero(unsigned int i, char *c)
{
	(void)i;
	*c = 0;
}

static int	test(void (*f)(unsigned int, char *))
{
	int		i;
	int		error;
	char	exp[256];
	char	got[256];

	error = 0;
	i = 0;
	while (i < 256)
	{
		exp[i] = i + 1;
		f(i, exp + i);
		got[i] = i + 1;
		i++;
	}
	exp[255] = 0;
	got[255] = 0;
	ft_striteri(got, f);
	error += btest_memory(0, exp, got, 256);
	exp[0] = '\0';
	got[0] = '\0';
	ft_striteri(got, f);
	error += btest_memory(1, exp, got, 256);
	return (error);
}

int	main(void)
{
	int		error;

	error = 0;
	error += test(increment);
	error += test(zero);
	btest_print_result(error);
}

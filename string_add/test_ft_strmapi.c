/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:21:51 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 11:26:59 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"
#include "btest.h"

static char	increment(unsigned int i, char c)
{
	if (c + i)
		return (c + i);
	return (1);
}

static char	zero(unsigned int i, char c)
{
	(void)c;
	(void)i;
	return (0);
}

static void	test_null(void)
{
	char	str[420];
	char	*got;

	memset(str, 1, 420);
	str[419] = '\0';
	got = ft_strmapi(str, zero);
	(void) got;
	free(got);
}

static int	test(char (*f)(unsigned int, char))
{
	int		i;
	int		error;
	char	exp[256];
	char	*got;

	error = 0;
	i = 0;
	while (i < 256)
	{
		exp[i] = i + 1;
		i++;
	}
	got = ft_strmapi(exp, f);
	i = 0;
	while (exp[i] != '\0')
	{
		exp[i] = f(i, exp[i]);
		i++;
	}
	error += btest_int(0, strlen(got), strlen(exp));
	error += btest_memory(0, exp, got, 255);
	free(got);
	return (error);
}

int	main(void)
{
	int		error;

	error = 0;
	error += test(increment);
	error += test(zero);
	test_null();
	btest_print_result(error);
}

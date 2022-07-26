/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:47:20 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 11:02:39 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"
#include "btest.h"

const char	g_src[] = "abcdefghijklmnopqrstuvwxyz0123456789";

static int	test(char *mem, int val, int n)
{
	void	*exp;
	void	*got;

	exp = memchr(mem, val, n);
	got = ft_memchr(mem, val, n);
	return (btest_pointer(n, exp, got));
}

int	main(void)
{
	int		error;
	char	mem[30];

	error = 0;
	memcpy(mem, g_src, 30);
	error += test(mem, 'a', 0);
	error += test(mem, 'i', 8);
	error += test(mem, 'i', 9);
	error += test(mem, 'i', 10);
	btest_print_result(error);
}

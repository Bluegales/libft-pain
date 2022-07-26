/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:19:54 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 11:02:46 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"
#include "btest.h"

const char	g_src[] = "abcdefghijklmnopqrstuvwxyz0123456789";

static int	test(char *buf1, char *buf2, int n)
{
	int	exp;
	int	got;

	exp = memcmp(buf1, buf2, n);
	got = ft_memcmp(buf1, buf2, n);
	return (btest_bool(n, exp, got));
}

int	main(void)
{
	int		error;
	char	buf1[30];
	char	buf2[30];

	error = 0;
	memset(buf1, 0, 30);
	memset(buf2, 10, 30);
	error += test(buf1, buf2, 0);
	error += test(buf1, buf2, 1);
	memcpy(buf1, g_src, 30);
	memcpy(buf2, g_src, 30);
	error += test(buf1, buf2, 30);
	buf1[10] = '-';
	error += test(buf1, buf2, 9);
	error += test(buf1, buf2, 10);
	error += test(buf1, buf2, 11);
	btest_print_result(error);
}

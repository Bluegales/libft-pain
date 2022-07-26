/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:31:19 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/16 00:49:27 by pfuchs           ###   ########.fr       */
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

	exp = strncmp(buf1, buf2, n);
	got = ft_strncmp(buf1, buf2, n);
	return (btest_int(n, exp, got));
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
	buf1[29] = '\0';
	buf2[29] = '\0';
	error += test(buf1, buf2, 30);
	error += test(buf1, buf2, 40);
	buf1[28] = '0';
	error += test(buf1, buf2, 28);
	error += test(buf1, buf2, 29);
	error += test(buf2, buf1, 28);
	error += test(buf2, buf1, 29);
	buf2[0] = 100;
	error += test(buf1, buf2, 20);
	error += test(buf2, buf1, 20);
	error += test("test\200", "test", 20);
	btest_print_result(error);
}

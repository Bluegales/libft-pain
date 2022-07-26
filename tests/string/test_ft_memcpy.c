/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:46:04 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 11:02:52 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"
#include "btest.h"

const char	g_src[] = "abcdefghijklmnopqrstuvwxyz0123456789";

static int	test(char *exp, char *got, int n)
{
	int		error;
	void	*got_return;

	error = 0;
	memcpy(exp, g_src, n);
	got_return = ft_memcpy(got, g_src, n);
	error += btest_memory(n, exp, got, 30);
	error += btest_pointer(n, got, got_return);
	return (error);
}

int	main(void)
{
	int		error;
	char	expected[30];
	char	got[30];

	error = 0;
	memset(expected, 42, 30);
	memset(got, 42, 30);
	error += test(expected, got, 0);
	error += test(expected, got, 5);
	error += test(expected, got, 20);
	btest_print_result(error);
}

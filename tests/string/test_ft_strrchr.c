/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:31:19 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 11:13:10 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"
#include "btest.h"

const char	g_src[] = "abcdefghijklmnopqrstuvwxyza";

static int	test(const char *mem, int val)
{
	void	*exp;
	void	*got;

	exp = strrchr(mem, val);
	got = ft_strrchr(mem, val);
	return (btest_pointer(val, exp, got));
}

int	main(void)
{
	int		error;

	error = 0;
	error += test(g_src, 'a');
	error += test(g_src, 'z');
	error += test(g_src, 'A');
	error += test(g_src, '\0');
	btest_print_result(error);
}

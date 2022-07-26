/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:31:19 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/16 00:47:13 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"
#include "btest.h"

const char	g_src[] = "abcdefghijklmnopqrstuvwxyz0123456789";

static int	test(const char *mem, int val)
{
	void	*exp;
	void	*got;

	exp = strchr(mem, val);
	got = ft_strchr(mem, val);
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

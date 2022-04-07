/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:47:25 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 11:02:59 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"
#include "btest.h"

const char	g_src[] = "abcdefghijklmnopqrstuvwxyz0123456789";

static int	test(int offset1, int offset2, int n)
{
	int		error;
	void	*got_return;
	char	exp_mem[30];
	char	got_mem[30];

	error = 0;
	memcpy(exp_mem, g_src, 30);
	memcpy(got_mem, g_src, 30);
	memmove(exp_mem + offset1, exp_mem + offset2, n);
	got_return = ft_memmove(got_mem + offset1, got_mem + offset2, n);
	error += btest_memory(n, exp_mem, got_mem, 30);
	error += btest_pointer(n, got_mem + offset1, got_return);
	return (error);
}

int	main(void)
{
	int	error;

	error = 0;
	error += test(0, 0, 0);
	error += test(0, 0, 20);
	error += test(5, 10, 10);
	error += test(10, 5, 10);
	error += test(5, 6, 10);
	error += test(6, 5, 10);
	btest_print_result(error);
}

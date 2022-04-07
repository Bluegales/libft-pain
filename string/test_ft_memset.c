/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:01:45 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 11:03:02 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"
#include "btest.h"

static int	test(char *exp, char *got, int val, int n)
{
	int		error;
	void	*got_return;

	error = 0;
	memset(exp, val, n);
	got_return = ft_memset(got, val, n);
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
	memset(expected, 10, 30);
	memset(got, 10, 30);
	error += test(expected, got, 20, 0);
	error += test(expected, got, 30, 10);
	error += test(expected, got, 40, 30);
	btest_print_result(error);
}

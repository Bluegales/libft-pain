/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:21:51 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 11:15:15 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"
#include "btest.h"

static int	test(char *exp, char *got, int n)
{
	int	error;

	error = 0;
	bzero(exp, n);
	ft_bzero(got, n);
	error += btest_memory(n, exp, got, 30);
	return (error);
}

int	main(void)
{
	int		error;
	char	exp[30];
	char	got[30];

	error = 0;
	error += test(exp, got, 30);
	memset(exp, 10, 30);
	memset(got, 10, 30);
	error += test(exp, got, 0);
	error += test(exp, got, 29);
	error += test(exp, got, 30);
	btest_print_result(error);
}

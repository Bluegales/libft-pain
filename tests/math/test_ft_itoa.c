/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 01:39:41 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/16 01:49:56 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libft.h"
#include "btest.h"

int	test(char *exp)
{
	int		error;
	char	*got;
	int		n;

	n = atoi(exp);
	error = 0;
	got = ft_itoa(atoi(exp));
	error += btest_memory(n, exp, got, strlen(exp) + 1);
	free(got);
	return (error);
}

int	main(void)
{
	int		error;

	error = 0;
	error += test("0");
	error += test("2147483647");
	error += test("-2147483648");
	error += test("-42");
	error += test("42");
	error += test("10");
	error += test("-10");
	btest_print_result(error);
}

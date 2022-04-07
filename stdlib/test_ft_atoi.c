/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:22:17 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 10:42:59 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "btest.h"

const char	*g_tests[] = {"0", "-0", "1", "2147483647", "-2147483648", "+1",
	"", "--1", "a1", "a-1", "\xff""1", "+-1", "-+1", "-+", "-", "+" "- 1",
	" 1", "   -1", "\x09""\x0a""\x0b""\x0c""\x0d""-1",
	"42 42", "42""\x09""42", "42a42", "42a-42", "42-42", "42+42"};

int	main(void)
{
	int	i;
	int	array_size;
	int	error;

	i = 0;
	error = 0;
	array_size = sizeof(g_tests) / sizeof(char *);
	while (i < array_size)
	{
		error += btest_int(i, atoi(g_tests[i]), ft_atoi(g_tests[i]));
		i++;
	}
	btest_print_result(error);
}

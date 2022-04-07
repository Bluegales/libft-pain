/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:31:19 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 11:07:03 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"
#include "btest.h"

const char	g_src0[1] = "";
const char	g_src1[10] = "abcdefghi";
const char	g_src2[30] = "abcdefghijklmnopqrstuvwxyz012";

int	test(const char *src)
{
	int	error;
	int	exp;
	int	got;

	error = 0;
	exp = strlen(src);
	got = ft_strlen(src);
	error += btest_int(0, exp, got);
	return (error);
}

int	main(void)
{
	int	error;

	error = 0;
	error += test(g_src0);
	error += test(g_src1);
	error += test(g_src2);
	btest_print_result(error);
}

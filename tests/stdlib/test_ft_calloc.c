/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:58:18 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 10:48:17 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h> // memset

#include "libft.h"
#include "btest.h"

int	main(void)
{
	int		error;
	char	*ptr;
	char	exp[300];

	error = 0;
	free(ft_calloc(0, 0));
	free(ft_calloc(1, 0));
	free(ft_calloc(0, 1));
	free(ft_calloc(1, 1));
	ptr = ft_calloc(50, 6);
	memset(exp, 0, 300);
	btest_memory(0, exp, ptr, 50 * 6);
	free(ptr);
	ptr = ft_calloc(420, 1);
	btest_pointer(420, NULL, ptr);
	free(ptr);
	btest_print_result(error);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:50:12 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/14 21:15:32 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <ctype.h>

#include "btest.h"
#include "ctype_test.h"

int	main(void)
{
	ctype_test_bool(ft_tolower, tolower);
}

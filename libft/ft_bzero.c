/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:11:51 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/22 16:45:28 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_memset

#include <stddef.h> // NULL size_t

// Sets "n" bytes from "mem" to 0
// use ft_memset instead
void	ft_bzero(void *mem, size_t n)
{
	ft_memset(mem, 0, n);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:28:17 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/31 21:55:44 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // t_list

// Returns the number of nodes
int	ft_lstsize(t_list *lst)
{
	t_list	*it;
	int		count;

	if (!lst)
		return (0);
	count = 1;
	it = lst;
	while (it->next)
	{
		it = it->next;
		count++;
	}
	return (count);
}

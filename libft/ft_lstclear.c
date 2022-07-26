/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:04:55 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/31 21:55:14 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // t_list

#include <stddef.h> // NULL size_t
#include <stdlib.h> // free

// Deletes and frees the given node and every successor of that node
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*it;
	t_list	*to_free;

	if (!lst)
		return ;
	it = *lst;
	while (it)
	{
		if (it->content)
			del(it->content);
		to_free = it;
		it = it->next;
		free(to_free);
	}
	*lst = NULL;
}

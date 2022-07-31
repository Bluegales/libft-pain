/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:35:13 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/31 23:04:41 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // t_list ft_lstnew

#include <stddef.h> // NULL size_t

// Creates a new list by applying "f" to every element of "lst"
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_list_it;
	t_list	*new_node;

	new_list = ft_lstnew(NULL);
	if (!new_list)
		return NULL;
	new_list->content = f(lst->content);
	new_list_it = new_list;
	lst = lst->next;
	while (lst)
	{
		new_node = ft_lstnew(NULL);
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_node->content = f(lst->content);
		new_list_it->next = new_node;
		new_list_it = new_node;
		lst = lst->next;
	}
	return (new_list);
}

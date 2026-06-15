/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:19:26 by fbarrada          #+#    #+#             */
/*   Updated: 2026/06/01 16:29:17 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(int), void (*del)(int))
{
	t_list	*new_list;
	t_list	*new_node;
	int	current_content;

	new_list = NULL;
	while (lst != NULL)
	{
		current_content = f(lst->value);
		new_node = ft_lstnew(current_content);
		if (!new_node)
		{
			del(current_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

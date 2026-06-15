/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:11:56 by fbarrada          #+#    #+#             */
/*   Updated: 2026/06/01 16:28:41 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;
	t_list	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current != NULL)
	{
		last = current;
		current = current->next;
	}
	return (last);
}

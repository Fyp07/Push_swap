/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listas_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:34:24 by fbarrada          #+#    #+#             */
/*   Updated: 2026/06/19 16:28:33 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_stack(char **str, int start)
{
	t_list *head;
	t_list *new;
	int	i;

	head = NULL;
	i = start;
	while (str[i])
	{
		new = ft_lstnew(ft_atoi(str[i]));
		if (!new)
			return (NULL);
		ft_lstadd_back(&head, new);
		i++;
	}
	return (head);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:34:24 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/13 16:35:28 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_stack(char **str, t_input *input, t_count *count)
{
	t_list	*head;
	t_list	*new;
	int		i;

	head = NULL;
	i = input->start;
	while (str[i])
	{
		new = ft_lstnew(ft_atoi(str[i]));
		if (!new)
			return (NULL);
		ft_lstadd_back(&head, new);
		input->count++;
		i++;
	}
	count->size_a = input->count;
	return (head);
}

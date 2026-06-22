/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listas_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:34:24 by fbarrada          #+#    #+#             */
/*   Updated: 2026/06/22 14:19:46 by fbarrada         ###   ########.fr       */
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

void	print_stack(t_list *stack, char *name)
{
	ft_printf("Stack %s: ", name);
	while (stack)
	{
		ft_printf("[%d]", stack->value);
		if (stack->next)
			ft_printf(" -> ");
		stack = stack->next;
	}
	ft_printf("\n");
}
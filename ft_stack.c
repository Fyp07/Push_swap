/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:34:24 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/07 15:34:02 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_stack(char **str, int start, t_input *input, t_count *count)
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
		input->count++;
		i++;
	}
	count->size_a = input->count;
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

void print_stack_a_b(t_list *stack_a, t_list *stack_b)
{
	printf("+---------+---------+\n");
	printf("| Stack A | Stack B |\n");
	printf("+---------+---------+\n");
	
	while (stack_a != NULL || stack_b != NULL)
	{
		if (stack_a)
		{
			printf("| %7d ", stack_a->value);
			stack_a = stack_a->next;
		}
		else
			printf("|         ");
	
		if (stack_b)
		{
			printf("| %7d |\n", stack_b->value);
			stack_b = stack_b->next;
		}
		else
			printf("|         |\n");
	}
	
	printf("+---------+---------+\n");
	
}
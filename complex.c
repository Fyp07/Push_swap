/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 11:24:19 by garodri2          #+#    #+#             */
/*   Updated: 2026/07/16 14:03:49 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bit(int value, int position)
{
	return ((value >> position) & 1);
}

t_list	*set_ranks_radix(t_list **stack, int total_size)
{
	t_list	*current;
	t_list	*compare;
	t_list	*head;
	int		rank_index;

	head = *stack;
	total_size = lstsize(head);
	current = head;
	while (current)
	{
		compare = head;
		rank_index = 0;
		while (compare)
		{
			if (current->value > compare->value)
				rank_index++;
			compare = compare->next;
		}
		current->rank = rank_index;
		current = current->next;
	}
	return (head);
}

void	complex_sort(t_list **stack_a, t_list **stack_b, t_count *count)
{
	int	i;
	int	position;

	position = 0;
	*stack_a = set_ranks_radix(stack_a, count->size_a);
	i = number_of_ranks(*stack_a);
	if (count->size_a <= 2)
		return (sort_two(stack_a, count));
	else if (count->size_a <= 5)
		return (sort_five(stack_a, stack_b, count));
	while (8 >= position)
	{
		i = number_of_ranks(*stack_a);
		while (i >= 0)
		{
			if (get_bit((*stack_a)->rank, position) == 0)
				pb(stack_b, stack_a, count);
			else
				ra(stack_a, count);
			i--;
		}
		go_back_home(stack_a, stack_b, count);
		position++;
	}
}

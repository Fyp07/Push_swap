/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garodri2 <garodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 11:24:19 by garodri2          #+#    #+#             */
/*   Updated: 2026/07/10 16:44:23 by garodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_bit(int value, int position)
{
	return((value >> position) & 1);
}

t_list	*set_ranks(t_list **stack, int total_size)
{
	t_list	*current;
	t_list	*compare;
	t_list	*head;
	int		rank_index;

	head = *stack;
	total_size = ft_lstsize(head);
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

void	complex_radix(t_list **stack_a, t_list **stack_b, t_count *count)
{	
	int	number_ranks;
	int position = 0;
	*stack_a = set_ranks(stack_a, count->size_a);
	number_ranks = number_of_ranks(*stack_a);
	
	int i = number_ranks;
	while(number_ranks > position)
	{
		
		while(i >= 0)
		{
			if(get_bit((*stack_a)->rank, position) == 0)
			{
				printf("\n rank: %d", (*stack_a)->rank);
				printf(" bit: %d", get_bit((*stack_a)->rank, position));
				//print_stack_a_b(*stack_a, *stack_b);
			}
			else
			{
				printf("\n rank: %d", (*stack_a)->rank);
				printf(" bit: %d", get_bit((*stack_a)->rank, position));
				
			}
			*stack_a = (*stack_a)->next;
			i --;
		}
		// go_back_home(stack_a, stack_b, count);
		// print_stack_a_b(*stack_a, *stack_b);
		position++;
	}
	printf("\n\n");
	print_stack_a_b(*stack_a, *stack_b);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 11:38:18 by garodri2          #+#    #+#             */
/*   Updated: 2026/07/16 14:03:49 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_to_insert(t_list *stack_b, int element_stack_a, int position_element_a,
		int size_stack_a)
{
	int	position_element_b;
	int	size_stack_b;
	int	cost_b;
	int	cost_a;

	position_element_b = nearest_position(stack_b, element_stack_a);
	if (position_element_a <= size_stack_a / 2)
		cost_a = position_element_a;
	else
		cost_a = size_stack_a - position_element_a;
	size_stack_b = lstsize(stack_b);
	if (position_element_b <= size_stack_b / 2)
		cost_b = position_element_b;
	else
		cost_b = size_stack_b - position_element_b;
	return (cost_a + cost_b);
}

void	go_min(t_list **stack_b, t_count *count)
{
	int	pos;
	int	size;
	int	i;

	pos = max_position(stack_b);
	size = lstsize(*stack_b);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(stack_b, count);
	}
	else
	{
		i = size - pos;
		while (i-- > 0)
			rrb(stack_b, count);
	}
}

void	go_back_home(t_list **stack_a, t_list **stack_b, t_count *count)
{
	while (*stack_b)
		pa(stack_a, stack_b, count);
}

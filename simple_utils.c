/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garodri2 <garodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 11:32:54 by garodri2          #+#    #+#             */
/*   Updated: 2026/07/15 11:34:17 by garodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_cheapest(t_list *stack_a, t_list *stack_b)
{
	t_list	*copy_stack_a;
	int		best_postion;
	int		min_cost;
	int		position;
	int		cost;

	copy_stack_a = stack_a;
	min_cost = INT_MAX;
	position = 0;
	best_postion = 0;
	while (copy_stack_a)
	{
		cost = cost_to_insert(stack_b, copy_stack_a->value, position,
				ft_lstsize(stack_a));
		if (cost < min_cost)
		{
			min_cost = cost;
			best_postion = position;
		}
		copy_stack_a = copy_stack_a->next;
		position++;
	}
	return (best_postion);
}
void	rotation_a(t_list **stack_a, t_count *count, int position)
{
	int	i;
	int	size_stack_a;

	size_stack_a = ft_lstsize(*stack_a);
	if (position <= size_stack_a / 2)
		while (position-- > 0)
			ra(stack_a, count);
	else
	{
		i = size_stack_a - position;
		while (i-- > 0)
			rra(stack_a, count);
	}
}
void	rotation_b(t_list **stack_b, t_count *count, int position)
{
	int	i;
	int	size_stack_b;

	size_stack_b = ft_lstsize(*stack_b);
	if (position <= size_stack_b / 2)
		while (position-- > 0)
			rb(stack_b, count);
	else
	{
		i = size_stack_b - position;
		while (i-- > 0)
			rrb(stack_b, count);
	}
}
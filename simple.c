/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:53:20 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/13 17:30:00 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_max(t_list *stack)
{
	int	max;
	int	pos;

	if (!stack)
		return (0);
	max = ft_lstmax(stack);
	pos = 0;
	while (stack)
	{
		if (stack->value == max)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (0);
}

int	nearest_position(t_list *stack_b, int value)
{
	int	min;
	int	max;
	int	pos;

	min = ft_lstmin(stack_b);
	max = ft_lstmax(stack_b);
	pos = 0;
	if (!stack_b)
		return (0);
	if (value < min || value > max)
		return (index_max(stack_b));
	while (stack_b && stack_b->next)
	{
		if (value < stack_b->value && value > stack_b->next->value)
			return (pos + 1);
		pos++;
		stack_b = stack_b->next;
	}
	return (pos + 1);
}

int	find_nearest(t_list **stack_b, int element_stack_a)
{
	return (nearest_position(*stack_b, element_stack_a));
}

int	cost_to_insert(t_list *stack_b, int element_stack_a, int position_element_a,
		int size_stack_a)
{
	int	position_element_b;
	int	size_stack_b;
	int	cost_b;
	int	cost_a;

	position_element_b = find_nearest(&stack_b, element_stack_a);
	if (position_element_a <= size_stack_a / 2)
		cost_a = position_element_a;
	else
		cost_a = size_stack_a - position_element_a;
	size_stack_b = ft_lstsize(stack_b);
	if (position_element_b <= size_stack_b / 2)
		cost_b = position_element_b;
	else
		cost_b = size_stack_b - position_element_b;
	return (cost_a + cost_b);
}

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

void	go_min(t_list **stack_b, t_count *count)
{
	int	pos;
	int	size;
	int	i;

	pos = index_max(*stack_b);
	size = ft_lstsize(*stack_b);
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
	{
		pa(stack_a, stack_b, count);
	}
}

void	simple_sort(t_list **stack_a, t_list **stack_b, t_count *count)
{
	int	position_to_insert;
	int	best_element_a;

	if (count->size_a <= 2)
		return (sort_two(stack_a, count));
	else if (count->size_a <= 5)
		return (sort_five(stack_a, stack_b, count));
	pb(stack_b, stack_a, count);
	while (*stack_a)
	{
		best_element_a = find_cheapest(*stack_a, *stack_b);
		rotation_a(stack_a, count, best_element_a);
		position_to_insert = find_nearest(stack_b, (*stack_a)->value);
		rotation_b(stack_b, count, position_to_insert);
		pb(stack_b, stack_a, count);
	}
	go_min(stack_b, count);
	go_back_home(stack_a, stack_b, count);
}

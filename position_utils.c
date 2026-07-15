/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garodri2 <garodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 11:25:59 by garodri2          #+#    #+#             */
/*   Updated: 2026/07/15 11:29:32 by garodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list **list)
{
	t_list	*min;
	t_list	*position;

	min = *list;
	position = (*list)->next;
	while (position)
	{
		if (position->value < min->value)
			min = position;
		position = position->next;
	}
	return (min);
}
t_list	*find_max(t_list **list)
{
	t_list	*max;
	t_list	*position;

	max = *list;
	position = (*list)->next;
	while (position)
	{
		if (position->value > max->value)
			max = position;
		position = position->next;
	}
	return (max);
}
int	max_position(t_list **list)
{
	t_list	*max;
	t_list	*walk;
	int	pos;

	max = find_max(list);
	walk = *list;
	pos = 0;
	while (walk)
	{
		if (walk->value == max->value)
			return(pos);
		pos++;
		walk = walk->next;
	}
	return (0);
}
int	min_position(t_list **list)
{
	t_list	*min;
	t_list	*walk;
	int	pos;

	min = find_min(list);
	walk = *list;
	pos = 0;
	while (walk)
	{
		if (walk->value == min->value)
			return(pos);
		pos++;
		walk = walk->next;
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
		return (max_position(&stack_b));
	while (stack_b && stack_b->next)
	{
		if (value < stack_b->value && value > stack_b->next->value)
			return (pos + 1);
		pos++;
		stack_b = stack_b->next;
	}
	return (pos + 1);
}
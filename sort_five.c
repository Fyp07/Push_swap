/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:19:31 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/06 16:47:53 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_list **list, t_count *count)
{
	if ((*list)->value > (*list)->next->value)
		sa(list, count);
}

void	sort_3(t_list **a, t_count *count)
{
	t_list	*position;

	position = *a;
	if (position == find_max(a) && position->next != find_min(a)) // 321
	{
		sa(a, count);
		rra(a, count);
	}
	else if (position == find_max(a) && position->next == find_min(a)) // 312
		ra(a, count);
	else if (position == find_min(a) && position->next == find_max(a)) // 132
	{
		sa(a, count);
		ra(a, count);
	}
	else if (position != find_max(a) && position->next == find_min(a)) // 213
		sa(a, count);
	else if (position != find_min(a) && position->next == find_max(a)) // 231
		rra(a, count);
}

void	sort_5(t_list **a, t_list **b, t_count *count, t_input	*input)
{
	int	min_pos;
	int	i;
	
	count->size_a = input->count;
	if (count->size_a == 1)
		return ;
	if (count->size_a == 2)
		return(sort_2(a, count));
	while (count->size_a > 3)
	{
		min_pos = min_position(a);
		if (min_pos <= count->size_a / 2)
			while (min_pos-- > 0)
				ra(a, count);
		else
		{
			i = count->size_a - min_pos;
			while (i-- > 0)
				rra(a, count);
		}
		pb(b, a, count);
	}
	sort_3(a, count);
	while ((*b))
		pa(a, b, count);
}

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

int	is_sorted(t_list **list)
{
	t_list	*position;

	position = *list;
	while (position->next)
	{
		if (position->value > position->next->value)
			return (0);
		position = position->next;
	}
	return (1);
}

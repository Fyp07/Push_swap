/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:19:31 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/02 14:38:46 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **a)
{
	t_list	*position;

	position = *a;
	if (position == find_max(a) && position->next != find_min(a)) // 321
	{
		sa(a);
		rra(a);
	}
	else if (position == find_max(a) && position->next == find_min(a)) // 312
		ra(a);
	else if (position == find_min(a) && position->next == find_max(a)) // 132
	{
		sa(a);
		ra(a);
	}
	else if (position != find_max(a) && position->next == find_min(a)) // 213
		sa(a);
	else if (position != find_min(a) && position->next == find_max(a)) // 231
		rra(a);
}

void	sort_5(t_list **a, t_list **b)
{
	t_list	*min;
	t_list	*position;
	int	i;
	
	position = *a;
	i = 0;
	while (i < ft_lstsize(*a) / 2)
	{
		min = find_min(a);
		if (position->value == min->value)
			pb(a, b);
		position = position->next;
		i++;
	}
	if (sizeof(a) == 3)
	{
		sort_3(a);
		if (!is_sorted(b))
			sb(b);
		pa(a, b);
		pa(a, b);
		return ;	
	}
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

int	is_sorted(t_list **list)
{
	t_list	*position;
	t_list	*other_position;

	position = *list;
	other_position = (*list)->next;
	while (position)
	{
		while (other_position)
		{
			if (position->value > other_position->value)
				return (0);
			other_position = other_position->next;
		}
		position = position->next;
	}
	return (1);
}

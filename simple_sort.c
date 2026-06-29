/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:19:31 by fbarrada          #+#    #+#             */
/*   Updated: 2026/06/29 14:54:59 by fbarrada         ###   ########.fr       */
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
	else if (position == find_min(a) && position->next != find_max(a)) // 123
		return ;
	else if (position == find_min(a) && position->next == find_max(a)) // 132
	{
		sa(a);
		ra(a);
	}
	else if (position != find_max(a) && position->next == find_min(a)) // 213
		sa(a);
	else if (position != find_min(a) && position->next == find_max(a))
		rra(a);
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
	t_list *max;
	t_list *position;

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
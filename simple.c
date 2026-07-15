/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garodri2 <garodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:53:20 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/15 11:39:53 by garodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		position_to_insert = nearest_position(*stack_b, (*stack_a)->value);
		rotation_b(stack_b, count, position_to_insert);
		pb(stack_b, stack_a, count);
	}
	go_min(stack_b, count);
	go_back_home(stack_a, stack_b, count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:09:12 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/16 14:09:53 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	disorder_check(t_list **stack_a, t_list **stack_b, t_input *input,
		t_count *count)
{
	if (input->disorder == 0)
		return ;
	if (input->disorder <= 0.2)
		simple_sort(stack_a, stack_b, count);
	else if (input->disorder < 0.5)
		medium_sort(stack_a, stack_b, count);
	else if (input->disorder >= 0.5)
		complex_sort(stack_a, stack_b, count);
}

void	strategy(t_list **stack_a, t_list **stack_b, t_input *input,
		t_count *count)
{
	input->disorder = compute_disorder(stack_a);
	if (count->size_a == 0)
		return ;
	if (input->disorder == 0)
	{
		if (input->bench == 1)
			print_bench(input, count);
		return ;
	}
	else if (input->strategy == ERROR)
		return ;
	else if (input->strategy == ADAPTIVE)
		disorder_check(stack_a, stack_b, input, count);
	else if (input->strategy == SIMPLE)
		simple_sort(stack_a, stack_b, count);
	else if (input->strategy == MEDIUM)
		medium_sort(stack_a, stack_b, count);
	else if (input->strategy == COMPLEX)
		complex_sort(stack_a, stack_b, count);
	if (input->bench == 1)
		print_bench(input, count);
}

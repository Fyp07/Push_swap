/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:48:54 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/16 13:48:58 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sum_operations(t_count *count)
{
	count->total = count->pa + count->pb + count->ra + count->rb + count->rr
		+ count->rra + count->rrb + count->rrr + count->sa + count->sb;
}

void	print_bench(t_input *input, t_count *count)
{
	int	i;

	sum_operations(count);
	i = (int)(input->disorder * 10);
	ft_printf("[bench] disorder: %f%%\n", input->disorder);
	if (i < 2 && input->strategy == ADAPTIVE)
		ft_printf("[bench] strategy: Adaptive / O(n²)\n");
	else if (i < 5 && input->strategy == ADAPTIVE)
		ft_printf("[bench] strategy: Adaptive / O(n√n)\n");
	else if (i >= 5 && input->strategy == ADAPTIVE)
		ft_printf("[bench] strategy: Adaptive / O(nlogn)\n");
	else if (input->strategy == SIMPLE)
		ft_printf("[bench] strategy: Simple / O(n²)\n");
	else if (input->strategy == MEDIUM)
		ft_printf("[bench] strategy: Medium / O(n√n)\n");
	else
		ft_printf("[bench] strategy: Complex / O(nlogn)\n");
	ft_printf("[bench] total_ops: %d\n", count->total);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", count->sa,
		count->sb, count->ss, count->pa, count->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		count->ra, count->rb, count->rr, count->rra, count->rrb, count->rrr);
}

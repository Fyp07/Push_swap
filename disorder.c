/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:43:17 by garodri2          #+#    #+#             */
/*   Updated: 2026/07/16 13:38:22 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_list **stack_a)
{
	float	mistakes;
	float	total_pairs;
	t_list	*walk;
	t_list	*next;

	mistakes = 0;
	total_pairs = 0;
	walk = *stack_a;
	while (walk)
	{
		next = walk->next;
		while (next)
		{
			total_pairs++;
			if (walk->value > next->value)
				mistakes++;
			next = next->next;
		}
		walk = walk->next;
	}
	return (mistakes / total_pairs);
}

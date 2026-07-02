/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garodri2 <garodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:53:20 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/02 12:15:11 by garodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(t_list *stack_a, t_list *stack_b)
{
	printf("+---------+---------+\n");
	printf("| Stack A | Stack B |\n");
	printf("+---------+---------+\n");
	
	while (stack_a != NULL || stack_b != NULL)
	{
		if (stack_a)
		{
			printf("| %7d ", stack_a->value);
			stack_a = stack_a->next;
		}
		else
			printf("|         ");
	
		if (stack_b)
		{
			printf("| %7d |\n", stack_b->value);
			stack_b = stack_b->next;
		}
		else
			printf("|         |\n");
	}
	
	printf("+---------+---------+\n");
	
}
// void	simple_insertion(t_list **stack)
// {
// 	t_list	*stack_a;
// 	t_list	*stack_b;
// 	int		nearest_smaller_one;
	
// 	stack_b  = NULL;
// 	stack_a = *stack;
	
// 	print_stacks(stack_a, stack_b);

// 	while(stack_a->value > stack_b->value)
// 	{
// 		if(stack_b->value > nearest_smaller_one)
// 			nearest_smaller_one = stack_b->value;
// 	}
	
// 	if(stack_a->value < stack_a->next->value)
// 	{
// 		pb(&stack_b, &stack_a);
// 	}
// 	print_stacks(stack_a, stack_b);
// }


// sa: troca os 2 primeiros elementos da stack A.
// sb: troca os 2 primeiros elementos da stack B.
// ss: faz sa e sb ao mesmo tempo.
// pa: move o primeiro elemento de B para o topo da A.
// pb: move o primeiro elemento de A para o topo da B.
// ra: roda a stack A para cima (o primeiro vai para o fim).
// rb: roda a stack B para cima (o primeiro vai para o fim).
// rr: faz ra e rb ao mesmo tempo.
// rra: roda a stack A para baixo (o último vai para o topo).
// rrb: roda a stack B para baixo (o último vai para o topo).
// rrr: faz rra e rrb ao mesmo tempo.


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garodri2 <garodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:53:20 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/02 16:13:39 by garodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_b(t_list **stack)
{
	t_list *stack_b;
	int	i;
	
	stack_b = *stack;
	i = 0;
	while(stack_b)
	{
		stack_b = stack_b->next;
		i ++;		
	}
	return(i);
}

void	simple_insertion(t_list **stack)
{
	t_list	*stack_a;
	t_list	*stack_b;
	//int		nearest_smaller_one = 0;
	//int	size;

	
	stack_b = NULL;
	stack_a = *stack;
	
	pb(&stack_b, &stack_a);
	while(stack_a)
	{
		print_stack_a_b(stack_a, stack_b);
		
		if(stack_a->value > stack_b->value) // Se Top_A > Top_B -> Puxa de A pra B
		{
			pb(&stack_b, &stack_a);
			print_stack_a_b(stack_a, stack_b);
		}
		if(stack_a->value < find_min(&stack_b)->value) // Se nenhum elemento de B menor que top A
		{
			ft_printf("ENTROU");
			pb(&stack_b, &stack_a);
			print_stack_a_b(stack_a, stack_b);
			rb(&stack_b);
			print_stack_a_b(stack_a, stack_b);
			//rb(&stack_b);
			
			// size = size_b(&stack_b);
			// while(size > 1)
			// {
			// 	rb(&stack_b);
			// 	size --;
			// 	print_stack_a_b(stack_a, stack_b);
			// }
		}
		
		// else
		// {
		// 	while(stack_b && nearest_smaller_one < stack_a ->value)
		// 	{
		// 		if(stack_b->value > nearest_smaller_one && stack_b->value < stack_a->value)
		// 		{
		// 			nearest_smaller_one = stack_b->value;
		// 			ft_printf("ENCONTROU UM MENOR");
		// 		}
		// 		stack_b = stack_b->next;
		// 	}
		// }
		printf("%d", size_b(&stack_b));
	}
	// if(stack_a->value < stack_a->next->value)
	// {
	// 	pb(&stack_b, &stack_a);
	// }
}


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


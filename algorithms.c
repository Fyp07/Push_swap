/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garodri2 <garodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:53:20 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/07 10:01:56 by garodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int nearest_position(t_list **list, int value) // Encontra a POSICAO do menor numero mais proximo de Top A
{
	int		min;
	t_list	*walk;
	int		pos;

	min = value;
	walk = *list;
	pos = 0;
	while (walk)
	{
		if (walk->value == min)
			return (pos);
		pos++;
		walk = walk->next;
	}
	return (0);
}

int	find_nearest(t_list **stack_b, int element_stack_a) // Encontra o menor VALOR mais proximo do Top A
{
	t_list	*search; // Copia da Stack B para andarmos por ela
	int		nearest_smaller_one; 

	search = *stack_b;
	nearest_smaller_one = INT_MIN; 
	while (search != NULL)
	{
		if (search->value > nearest_smaller_one && search->value < element_stack_a) // Se o menor valor da Stack B for maior que o menor mais proximo && Stack B menor que Stack A menor mais proximo atualiza o valor
		{
			nearest_smaller_one = search->value;
		}
		search = search->next;
	}
	return (nearest_position(stack_b, nearest_smaller_one)); // Retorna posicao do menor mais proximo
}


int	cost_to_insert(t_list *stack_b, int element_stack_a, int position_element_a, int size_stack_a)
{
	int position_element_b;
	int size_stack_b;
	int cost_b;
	int cost_a;

	position_element_b = find_nearest(&stack_b, element_stack_a);
	if(position_element_a <= size_stack_a / 2)
		cost_a = position_element_a;
	else
		cost_a = size_stack_a - position_element_a;
	size_stack_b = ft_lstsize(stack_b);
	if(position_element_b <= size_stack_b / 2)
		cost_b = position_element_b;
	else 
		cost_b = size_stack_b - position_element_b;
	return(cost_a + cost_b);
}


void	rotation_b(t_list **stack_a, t_list **stack_b, t_count *count, int position) // Rotaciona a Stack B
{
	int	i;

	if (position <= count->size_b / 2)
		while (position-- > 0)
			rb(stack_b, count);
	else
	{
		i = count->size_b - position;
		while (i-- > 0)
			rrb(stack_b, count);
	}
	pb(stack_b, stack_a, count);
}

void	simple_insertion(t_list **stack_a, t_list **stack_b, t_count *count) // Maestro da orquestra 
{
	print_stack_a_b(*stack_a, *stack_b);
	while (*stack_a != NULL)
	{
		rotation_b(stack_a, stack_b, count, find_nearest(stack_a, stack_b));
	}
	print_stack_a_b(*stack_a, *stack_b);
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

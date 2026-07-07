/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garodri2 <garodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:53:20 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/07 12:38:25 by garodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_max(t_list *stack)
{
	int	max;
	int	pos;

	if (!stack)
		return (0);
	max = ft_lstmax(stack);
	pos = 0;
	while (stack)
	{
		if (stack->value == max)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (0);
}

int nearest_position(t_list *stack_b, int value) 
{
	int		min;
	int 	max;
	int		pos;

	min = ft_lstmin(stack_b);
	max = ft_lstmax(stack_b);
	pos = 0;
	if(!stack_b)
		return(0);
	if(value < min || value > max)
		return(index_max(stack_b));
	while (stack_b && stack_b ->next)
	{
		if (value < stack_b->value && value > stack_b->next->value)
			return (pos + 1);
		pos++;
		stack_b = stack_b->next;
	}
	return (pos + 1);
}

// int	find_nearest(t_list **stack_b, int element_stack_a) // Encontra o menor VALOR mais proximo do Top A
// {
// 	t_list	*search; // Copia da Stack B para andarmos por ela
// 	int		nearest_smaller_one; 

// 	search = *stack_b;
// 	nearest_smaller_one = INT_MIN; 
	
// 	while (search && search->next)
// 	{
// 		if (search->value > nearest_smaller_one && search->value < element_stack_a) // Se o menor valor da Stack B for maior que o menor mais proximo && Stack B menor que Stack A menor mais proximo atualiza o valor
// 		{
// 			nearest_smaller_one = search->value;
// 		}
// 		search = search->next;
// 	}
// 	return (nearest_position(*stack_b, nearest_smaller_one)); // Retorna posicao do menor mais proximo
// }


int	cost_to_insert(t_list *stack_b, int element_stack_a, int position_element_a, int size_stack_a)
{
	int position_element_b;
	int size_stack_b;
	int cost_b;
	int cost_a;

	position_element_b = nearest_position(stack_b, element_stack_a);
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


int search_cheapest(t_list *stack_a, t_list *stack_b)
{
	t_list *copy_stack_a;
	int best_postion;
	int	min_cost;
	int position;
	int cost;

	copy_stack_a = stack_a;
	min_cost = INT_MAX;
	position = 0;
	best_postion = 0;
	while(copy_stack_a)
	{
		cost = cost_to_insert(stack_b, copy_stack_a->value, position, ft_lstsize(stack_a));
		if(cost < min_cost)
		{
			min_cost = cost;
			best_postion = position;
		}
		copy_stack_a = copy_stack_a->next;
		position ++;
	}
	return(best_postion);
}

void	rotation_b(t_list **stack_b, t_count *count, int position) // Rotaciona a Stack B
{
	int	i;
	int size_stack_b;
	
	size_stack_b = ft_lstsize(*stack_b);
	if (position <= count->size_b / 2)
		while (position-- > 0)
			rb(stack_b, count);
	else
	{
		i = size_stack_b - position;
		while (i-- > 0)
			rrb(stack_b, count);
	}
}

void	rotation_a(t_list **stack_a, t_count *count, int position) // Rotaciona a Stack B
{
	int	i;
	int size_stack_a;
	
	size_stack_a = ft_lstsize(*stack_a);
	if (position <= count->size_b / 2)
		while (position-- > 0)
			rb(stack_a, count);
	else
	{
		i = size_stack_a - position;
		while (i-- > 0)
			rrb(stack_a, count);
	}
}

void	simple_insertion(t_list **stack_a, t_list **stack_b, t_count *count) // Maestro da orquestra 
{
	int position_to_insert;
	int best_element_a;

	pb(stack_b, stack_a, count);
	//print_stack_a_b(*stack_a, *stack_b);
	while(*stack_a)
	{
		best_element_a = search_cheapest(*stack_a, *stack_b);
		
		rotation_a(stack_a, count, best_element_a);
	//	print_stack_a_b(*stack_a, *stack_b);
		
		position_to_insert = nearest_position(*stack_b, (*stack_a)->value);
		
		rotation_b(stack_b, count, position_to_insert);
	//	print_stack_a_b(*stack_a, *stack_b);
		
		pb(stack_b, stack_a, count);
	//	print_stack_a_b(*stack_a, *stack_b);
	}
	//printf("CHEGOU NO FINAL");
	
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

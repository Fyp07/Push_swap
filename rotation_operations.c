/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garodri2 <garodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 11:45:47 by garodri2          #+#    #+#             */
/*   Updated: 2026/07/15 11:46:22 by garodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **list_a, t_count *count)
{
	t_list *head;
	t_list *last;
	t_list *temp;
	
	head = *list_a;
	last = ft_lstlast(*list_a);
	temp = head->next;
	
	last->next = head;
	head->next = NULL;
	head->previous = last;
	
	temp->previous = NULL;
	*list_a = temp;
	count->ra++;
	write(1, "ra\n", 3);
}

void	rb(t_list **list_b, t_count *count)
{
	t_list *head;
	t_list *last;
	t_list *temp;
	
	head = *list_b;
	last = ft_lstlast(*list_b);
	temp = head->next;
	
	last->next = head;
	head->next = NULL;
	head->previous = last;
	
	temp->previous = NULL;
	*list_b = temp;
	count->rb++;
	write(1, "rb\n", 3);
}

void	rr(t_list **list_b, t_list **list_a, t_count *count)
{
	ra(list_a, count);
	count->ra--;
	rb(list_b, count);
	count->rb--;
	count->rr++;
	write(1, "rr\n", 3);
}

void	rra(t_list **list_a, t_count *count)
{
	t_list *head;
	t_list *last;
	t_list *temp;
	
	head = *list_a;
	last = ft_lstlast(*list_a);
	temp = last->previous;

	head->previous = last;
	last->next = head;
	temp->next = NULL; 
	last->previous = NULL;
	*list_a = last;
	count->rra++;
	write(1, "rra\n", 4);
}

void	rrb(t_list **list_b, t_count *count)
{
	t_list *head;
	t_list *last;
	t_list *temp;
	
	head = *list_b;
	last = ft_lstlast(*list_b);
	temp = last->previous;

	head->previous = last;
	last->next = head;
	temp->next = NULL; 
	last->previous = NULL;
	*list_b = last;
	count->rrb++;
	write(1, "rrb\n", 4);
}

void	rrr(t_list **list_a, t_list **list_b, t_count *count)
{
	rra(list_a, count);
	count->rra--;
	rrb(list_b, count);
	count->rrb--;
	count->rrr++;
	write(1, "rrr\n", 4);
}
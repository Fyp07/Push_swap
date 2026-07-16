/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:10:31 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/16 14:11:48 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **list_a, t_count *count)
{
	t_list	*head;
	t_list	*last;
	t_list	*temp;

	head = *list_a;
	last = lstlast(*list_a);
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
	t_list	*head;
	t_list	*last;
	t_list	*temp;

	head = *list_b;
	last = lstlast(*list_b);
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

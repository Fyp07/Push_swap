/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:39:50 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/16 14:05:52 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include "push_swap.h"

void	sa(t_list **list_a, t_count *count)
{
	t_list	*head;
	t_list	*node2;
	t_list	*node3;

	if (!list_a || !(*list_a)->next)
		return ;
	head = *list_a;
	node2 = head->next;
	node3 = node2->next;
	head->next = node3;
	head->previous = node2;
	node2->next = head;
	node2->previous = NULL;
	node3->previous = head;
	*list_a = node2;
	count->sa++;
	write(1, "sa\n", 3);
}

void	sb(t_list **list_b, t_count *count)
{
	t_list	*head;
	t_list	*node2;
	t_list	*node3;

	if (!list_b || !(*list_b)->next)
		return ;
	head = *list_b;
	node2 = head->next;
	node3 = node2->next;
	head->next = node3;
	head->previous = node2;
	node2->next = head;
	node2->previous = NULL;
	node3->previous = head;
	*list_b = node2;
	count->sb++;
	write(1, "sb\n", 3);
}

void	ss(t_list **list_a, t_list **list_b, t_count *count)
{
	sa(list_a, count);
	count->sa--;
	sb(list_b, count);
	count->sb--;
	count->ss++;
	write(1, "ss\n", 3);
}

void	pa(t_list **list_a, t_list **list_b, t_count *count)
{
	t_list	*temp;
	t_list	*head_a;

	if (!list_b || !(*list_b))
		return ;
	temp = (*list_b)->next;
	if ((*list_a))
	{
		head_a = *list_a;
		lstadd_front(list_a, (*list_b));
		(*list_b) = temp;
		head_a->previous = *list_a;
		(*list_a)->next = head_a;
	}
	else
	{
		lstadd_front(list_a, (*list_b));
		temp->previous = NULL;
		(*list_b) = temp;
	}
	count->pa++;
	count->size_b--;
	count->size_a++;
	write(1, "pa\n", 3);
}

void	pb(t_list **list_b, t_list **list_a, t_count *count)
{
	t_list	*temp;
	t_list	*head_b;

	if (!list_a || !(*list_a))
		return ;
	temp = (*list_a)->next;
	if ((*list_b))
	{
		head_b = *list_b;
		lstadd_front(list_b, (*list_a));
		(*list_a) = temp;
		head_b->previous = *list_b;
		(*list_b)->next = head_b;
	}
	else
	{
		lstadd_front(list_b, (*list_a));
		temp->previous = NULL;
		(*list_a) = temp;
	}
	count->pb++;
	count->size_a--;
	count->size_b++;
	write(1, "pb\n", 3);
}

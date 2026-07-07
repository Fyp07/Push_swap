/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:39:50 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/07 18:05:29 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./Libft/libft.h"

void	sa(t_list **list_a, t_count *count)
{
	t_list	*head;
	t_list	*node2;
	t_list	*node3;
	
	if (!list_a || !(*list_a)->next)
		return ;
		
	// Atribuindo valores
	head = *list_a;
	node2 = head->next;
	node3 = node2->next;

	// Troca
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
		
	// Atribuindo valores
	head = *list_b;
	node2 = head->next;
	node3 = node2->next;

	// Troca
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
	t_list *temp;
	t_list *head_a;
	
	if (!list_b || !(*list_b))
		return ;

	temp = (*list_b)->next;
	if ((*list_a))
	{
		head_a = *list_a;
		ft_lstadd_front(list_a, (*list_b));
		(*list_b) = temp;
		head_a->previous = *list_a;
		(*list_a)->next = head_a;
	}
	else
	{
		ft_lstadd_front(list_a, (*list_b));
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
	t_list *temp;
	t_list *head_b;
	
	if (!list_a || !(*list_a))
		return ;

	temp = (*list_a)->next;
	if ((*list_b))
	{
		head_b = *list_b;
		ft_lstadd_front(list_b, (*list_a));
		(*list_a) = temp;
		head_b->previous = *list_b;
		(*list_b)->next = head_b;
	}
	else
	{
		ft_lstadd_front(list_b, (*list_a));
		temp->previous = NULL;
		(*list_a) = temp;
	}
	count->pb++;
	count->size_a--;
	count->size_b++;
	write(1, "pb\n", 3);
}

void	ra(t_list **list_a, t_count *count)
{
	t_list *head;
	t_list *last;
	t_list *temp;
	
	head = *list_a; // Define a cabeca da lista
	last = ft_lstlast(*list_a); // Define o final da lista
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
	
	head = *list_b; // Define a cabeca da lista
	last = ft_lstlast(*list_b); // Define o final da lista
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
	
	head = *list_a; // Define a cabeca da lista
	last = ft_lstlast(*list_a); // Define o final da lista
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
	
	head = *list_b; // Define a cabeca da lista
	last = ft_lstlast(*list_b); // Define o final da lista
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
	count->rra--;
	count->rrr++;
	write(1, "rrr\n", 4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garodri2 <garodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:39:50 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/04 11:53:45 by garodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./Libft/libft.h"

void	sa(t_list **lista_a, t_count *count)
{
	t_list	*head;
	t_list	*node2;
	t_list	*node3;
	
	if (!lista_a || !(*lista_a)->next)
		return ;
		
	// Atribuindo valores
	head = *lista_a;
	node2 = head->next;
	node3 = node2->next;

	// Troca
	head->next = node3;
	head->previous = node2;
	
	node2->next = head;
	node2->previous = NULL;

	node3->previous = head;

	*lista_a = node2;
	count->sa++;
	write(1, "sa\n", 3);
}

void	sb(t_list **lista_b, t_count *count)
{
	t_list	*head;
	t_list	*node2;
	t_list	*node3;
	
	if (!lista_b || !(*lista_b)->next)
		return ;
		
	// Atribuindo valores
	head = *lista_b;
	node2 = head->next;
	node3 = node2->next;

	// Troca
	head->next = node3;
	head->previous = node2;
	
	node2->next = head;
	node2->previous = NULL;

	node3->previous = head;

	*lista_b = node2;
	count->sb++;
	write(1, "sb\n", 3);
}

void	ss(t_list **lista_a, t_list **lista_b, t_count *count)
{
	sa(lista_a, count);
	count->sa--;
	sb(lista_b, count);
	count->sb--;
	count->ss++;
	write(1, "ss\n", 3);
}

void	pa(t_list **lista_a, t_list **lista_b, t_count *count)
{
	t_list *temp;
	t_list *head_a;
	
	if (!lista_b || !(*lista_b))
		return ;

	temp = (*lista_b)->next;
	if ((*lista_a))
	{
		head_a = *lista_a;
		ft_lstadd_front(lista_a, (*lista_b));
		(*lista_b) = temp;
		head_a->previous = *lista_a;
		(*lista_a)->next = head_a;
	}
	else
	{
		ft_lstadd_front(lista_a, (*lista_b));
		temp->previous = NULL;
		(*lista_b) = temp;
	}
	count->pa++;
	count->size_b--;
	count->size_a++;
	write(1, "pa\n", 3);
}

void	pb(t_list **lista_b, t_list **lista_a, t_count *count)
{
	t_list *temp;
	t_list *head_b;
	
	if (!lista_a || !(*lista_a))
		return ;

	temp = (*lista_a)->next;
	if ((*lista_b))
	{
		head_b = *lista_b;
		ft_lstadd_front(lista_b, (*lista_a));
		(*lista_a) = temp;
		head_b->previous = *lista_b;
		(*lista_b)->next = head_b;
	}
	else
	{
		ft_lstadd_front(lista_b, (*lista_a));
		temp->previous = NULL;
		(*lista_a) = temp;
	}
	count->pb++;
	count->size_a--;
	count->size_b++;
	write(1, "pb\n", 3);
}

void	ra(t_list **lista_a, t_count *count)
{
	t_list *head;
	t_list *last;
	t_list *temp;
	
	head = *lista_a; // Define a cabeca da lista
	last = ft_lstlast(*lista_a); // Define o final da lista
	temp = head->next;
	
	last->next = head;
	head->next = NULL;
	head->previous = last;
	
	temp->previous = NULL;
	*lista_a = temp;
	count->ra++;
	write(1, "ra\n", 3);
}

void	rb(t_list **lista_b, t_count *count)
{
	t_list *head;
	t_list *last;
	t_list *temp;
	
	head = *lista_b; // Define a cabeca da lista
	last = ft_lstlast(*lista_b); // Define o final da lista
	temp = head->next;
	
	last->next = head;
	head->next = NULL;
	head->previous = last;
	
	temp->previous = NULL;
	*lista_b = temp;
	count->rb++;
	write(1, "rb\n", 3);
}

void	rr(t_list **lista_b, t_list **lista_a, t_count *count)
{
	ra(lista_a, count);
	count->ra--;
	rb(lista_b, count);
	count->rb--;
	count->rr++;
	write(1, "rr\n", 3);
}

void	rra(t_list **lista_a, t_count *count)
{
	t_list *head;
	t_list *last;
	t_list *temp;
	
	head = *lista_a; // Define a cabeca da lista
	last = ft_lstlast(*lista_a); // Define o final da lista
	temp = last->previous;

	head->previous = last;
	last->next = head;
	temp->next = NULL; 
	last->previous = NULL;
	*lista_a = last;
	count->rra++;
	write(1, "rra\n", 4);
}

void	rrb(t_list **lista_b, t_count *count)
{
	t_list *head;
	t_list *last;
	t_list *temp;
	
	head = *lista_b; // Define a cabeca da lista
	last = ft_lstlast(*lista_b); // Define o final da lista
	temp = last->previous;

	head->previous = last;
	last->next = head;
	temp->next = NULL; 
	last->previous = NULL;
	*lista_b = last;
	count->rrb++;
	write(1, "rrb\n", 4);
}

void	rrr(t_list **lista_a, t_list **lista_b, t_count *count)
{
	rra(lista_a, count);
	count->rra--;
	rrb(lista_b, count);
	count->rra--;
	count->rrr++;
	write(1, "rrr\n", 4);
}

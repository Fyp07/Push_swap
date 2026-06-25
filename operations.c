/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:39:50 by fbarrada          #+#    #+#             */
/*   Updated: 2026/06/25 14:08:39 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./Libft/libft.h"

void	sa(t_list **lista_a)
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
}

void	sb(t_list **lista_b)
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
}

void	ss(t_list **lista_a, t_list **lista_b)
{
	sa(lista_a);
	sb(lista_b);
}

void	pa(t_list **lista_a, t_list *node_b)
{
	t_list *temp;
	t_list *head_a;
	
	if (!node_b)
		return ;

	temp = node_b->next;
	if ((*lista_a)->next)
	{
		head_a = *lista_a;
		ft_lstadd_front(lista_a, node_b);
		node_b = temp;
		head_a->previous = *lista_a;
		(*lista_a)->next = head_a;
	}
	else
	{
		ft_lstadd_front(lista_a, node_b);
		node_b = temp;
	}
}

void	pb(t_list **lista_b, t_list *node_a)
{
	t_list *temp;
	t_list *head_b;
	
	if (!node_a)
		return ;

	temp = node_a->next;
	if ((*lista_b))
	{
		head_b = *lista_b;
		ft_lstadd_front(lista_b, node_a);
		node_a = temp;
		head_b->previous = *lista_b;
		(*lista_b)->next = head_b;
	}
	else
	{
		ft_lstadd_front(lista_b, node_a);
		ft_printf("%d\n", node_a->value);
		node_a = temp;
		ft_printf("%d\n", node_a->value);
		
	}
}

void	ra(t_list **lista_a)
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
	head->previous = last;
	
	temp->previous = NULL;
	*lista_a = temp;
}

void	rb(t_list **lista_b)
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
	head->previous = last;
	
	temp->previous = NULL;
	*lista_b = temp;
}

void	rr(t_list **lista_b, t_list **lista_a)
{
	ra(lista_a);
	rb(lista_b);
}

// void	rra(t_list **lista_a)
// {
// 	t_list *last;
	
// 	last = ft_lstlast(*lista_a);
// 	ft_lstadd_front(lista_a, last);
// }

// void	rrb(t_list **lista_b)
// {
// 	rra(lista_b);
// }

// void	rrr(t_list **lista_a, t_list **lista_b)
// {
// 	rra(lista_a);
// 	rrb(lista_b);
// }

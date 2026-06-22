/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:39:50 by fbarrada          #+#    #+#             */
/*   Updated: 2026/06/22 14:23:25 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./Libft/libft.h"

// void	sa(t_list **lista)
// {
// 	int	temp;
	
// 	if (!lista || (*lista)->next == NULL)
// 		return ;
	
// 	temp = (*lista)->value;
// 	(*lista)->value = (*lista)->next->value;
// 	(*lista)->next->value = temp;
// }

// void	sb(t_list **lista)
// {
// 	sa(lista);
// }

// void	ss(t_list **lista_a, t_list **lista_b)
// {
// 	sa(lista_a);
// 	sb(lista_b);
// }

// void	pa(t_list **lista_a, t_list *lista_b)
// {
// 	if (!lista_b)
// 		return ;
// 	ft_lstadd_front(lista_a, lista_b);
// }

// void	pb(t_list **lista_b, t_list **lista_a)
// {
// 	pa(lista_b, lista_a);
// }

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

// void	rb(t_list **lista_b)
// {
// 	ra(lista_b);
// }

// void	rr(t_list **lista_b, t_list **lista_a)
// {
// 	ra(lista_a);
// 	rb(lista_b);
// }

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

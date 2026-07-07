/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garodri2 <garodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 12:26:47 by garodri2          #+#    #+#             */
/*   Updated: 2026/07/07 12:27:34 by garodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		i;

	current = lst;
	i = 0;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

int	ft_lstmin(t_list *lst)
{
	int	min;

	if (!lst)
		return (0);
	min = lst->value;
	while (lst)
	{
		if (lst->value < min)
			min = lst->value;
		lst = lst->next;
	}
	return (min);
}

int	ft_lstmax(t_list *lst)
{
	int	max;

	if (!lst)
		return (0);
	max = lst->value;
	while (lst)
	{
		if (lst->value > max)
			max = lst->value;
		lst = lst->next;
	}
	return (max);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 18:14:17 by fbarrada          #+#    #+#             */
/*   Updated: 2026/06/18 14:19:49 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->value);
		lst = lst->next;
	}
}

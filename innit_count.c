/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 14:09:50 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/03 14:15:18 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_count	*innit_count(void)
{
	t_count	*count;
	
	count = malloc(sizeof(t_count));
	if (!count)
		return (NULL);

	count->pa = 0;
	count->pb = 0;
	count->sa = 0;
	count->sb = 0;
	count->ss = 0;
	count->ra = 0;
	count->rb = 0;
	count->rr = 0;
	count->rra = 0;
	count->rrb = 0;
	count->rrr = 0;
	count->size_a = 0;
	count->size_b = 0;
	return (count);
}
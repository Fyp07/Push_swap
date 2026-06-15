/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:10:10 by fbarrada          #+#    #+#             */
/*   Updated: 2026/05/13 18:13:20 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrdest;
	unsigned char	*ptrsrc;
	size_t			i;

	i = 0;
	if ((dest == NULL) && (src == NULL))
		return (NULL);
	ptrdest = (unsigned char *)dest;
	ptrsrc = (unsigned char *)src;
	if ((ptrdest > ptrsrc) && (src + n > dest))
	{
		while (n > 0)
		{
			ptrdest[n - 1] = ptrsrc[n - 1];
			n--;
		}
		return (dest);
	}
	while (i < n)
	{
		ptrdest[i] = ptrsrc[i];
		i++;
	}
	return (dest);
}

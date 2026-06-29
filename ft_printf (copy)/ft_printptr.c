/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:52:17 by fbarrada          #+#    #+#             */
/*   Updated: 2026/05/18 12:15:51 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printhexptr(unsigned long n)
{
	int	cont;

	cont = 0;
	if (n > 15)
		cont += ft_printhexptr(n / 16);
	cont += ft_printchar("0123456789abcdef"[n % 16]);
	return (cont);
}

int	ft_printptr(void *ptr)
{
	int	cont;

	cont = 2;
	if (!ptr)
		return (ft_printstr("(nil)"));
	write(1, "0x", 2);
	cont += ft_printhexptr((unsigned long)ptr);
	return (cont);
}

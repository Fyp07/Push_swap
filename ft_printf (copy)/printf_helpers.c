/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:38:41 by fbarrada          #+#    #+#             */
/*   Updated: 2026/05/26 16:01:26 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_printstr("(null)"));
	while (str[i])
		ft_printchar(str[i++]);
	return (i);
}

int	ft_printnbr(long n)
{
	int	cont;

	cont = 0;
	if (n < 0)
	{
		cont += ft_printchar('-');
		n = -n;
	}
	if (n > 9)
		cont += ft_printnbr(n / 10);
	cont += ft_printchar((n % 10) + 48);
	return (cont);
}

int	ft_printunsnbr(unsigned int n)
{
	int	cont;

	cont = 0;
	if (n > 9)
		cont += ft_printunsnbr(n / 10);
	cont += ft_printchar((n % 10) + 48);
	return (cont);
}

int	ft_printhex(char str, unsigned int n)
{
	int	cont;

	cont = 0;
	if (n > 15)
		cont += ft_printhex(str, (n / 16));
	if (str == 'x')
		cont += ft_printchar("0123456789abcdef"[n % 16]);
	else
		cont += ft_printchar("0123456789ABCDEF"[n % 16]);
	return (cont);
}

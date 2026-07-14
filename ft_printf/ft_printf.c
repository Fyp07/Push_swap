/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:33:05 by fbarrada          #+#    #+#             */
/*   Updated: 2026/05/26 16:04:24 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check(const char *str, int i, int cont, va_list args)
{
	if (str[i + 1] == '%')
		return ((ft_printchar('%')));
	else if (str[i + 1] == 'c')
		return ((ft_printchar(va_arg(args, int))));
	else if (str[i + 1] == 's')
		return ((ft_printstr(va_arg(args, char *))));
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		return ((ft_printnbr(va_arg(args, int))));
	else if (str[i + 1] == 'u')
		return ((ft_printunsnbr(va_arg(args, unsigned int))));
	else if (str[i + 1] == 'x')
		return ((ft_printhex('x', va_arg(args, unsigned int))));
	else if (str[i + 1] == 'X')
		return ((ft_printhex('X', va_arg(args, unsigned int))));
	else if (str[i + 1] == 'p')
		return ((ft_printptr(va_arg(args, void *))));
	return (cont);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		cont;

	va_start(args, str);
	i = 0;
	cont = 0;
	while (str[i])
	{
		if (str[i] == '%')
			cont += check(str, i++, cont, args);
		else
			cont += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (cont);
}

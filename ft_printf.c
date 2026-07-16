/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:49:56 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/16 13:49:58 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printchar(char c)
{
	write(2, &c, 1);
}

void	ft_printstr(char *str)
{
	while (*str)
		ft_printchar(*str++);
}

void	ft_printnbr(int n)
{
	if (n > 9)
		ft_printnbr(n / 10);
	ft_printchar((n % 10) + 48);
}

void	ft_print_double(double n)
{
	int	i;
	int	f;

	n *= 100;
	i = (int)n;
	f = (int)((n - i) * 100);
	ft_printnbr(i);
	ft_printchar('.');
	if (f < 10)
		ft_printchar('0');
	ft_printnbr(f);
}

void	ft_printf(char *str, ...)
{
	va_list	args;
	int		i;

	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				ft_printstr(va_arg(args, char *));
			else if (str[i] == 'f')
				ft_print_double(va_arg(args, double));
			else if (str[i] == 'd' || str[i] == 'i')
				ft_printnbr(va_arg(args, int));
			else if (str[i] == '%')
				ft_printchar('%');
		}
		else
			ft_printchar(str[i]);
		i++;
	}
	va_end(args);
}

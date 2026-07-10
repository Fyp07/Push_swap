
#include "push_swap.h"

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

void	ft_print_double(double n)
{
	int	i;
	int	f;

	n *= 100;
	i = (int)n;
	f = (int)((n - i) * 100);
	ft_putnbr(i);
	ft_putchar('.');
	if (f < 10)
		ft_putchar('0');
	ft_putnbr(f);
}

void	ft_printf(char *str, ...)
{
	va_list args;
	int	i;

	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
				ft_printchar(va_arg(args, char));
			else if (str[i] == 's')
				ft_printstr(va_arg(args, char *));
			else if (str[i] == 'f')
				ft_print_double(va_arg(args, double));
			else if (str[i] == 'd' || str[i] == 'i')
				ft_printnbr(va_arg(args, int));
			else if (str[i] == '%')
				ft_putchar('%');
		}
		else
			ft_printchar(str[i]);
		i++;
	}
	va_end(args);
}
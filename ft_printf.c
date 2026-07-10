
#include "push_swap.h"

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
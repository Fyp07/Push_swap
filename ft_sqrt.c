
#include "push_swap.h"

int	ft_sqrt(int	num)
{
	int	i;

	i = 0;
	while (i * i <= num)
	{
		if (i * i == num)
			return (i);
		i++;
	}
	return (i - 1);	
}

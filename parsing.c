/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:49:16 by fbarrada          #+#    #+#             */
/*   Updated: 2026/06/18 13:56:33 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_errors(char **numbers)
{
	int	i;
	
	i = 0;
	while (numbers[i])
	{
		if (is_not_num(numbers[i]))
			return (1);
		if (in_range(numbers[i]))
			return (1);
		i++;
	}
	if (has_repeated(numbers))
		return (1);
	return (0);
}

void	validate_flags(int argc, char **argv, t_input *input)
{
	int	i;

	i = 1;
	input->bench = 0;
	input->strategy = ADAPTIVE;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strncmp(argv[i], "--simple", 8) == 0)
			input->strategy = SIMPLE;
		else if (ft_strncmp(argv[i], "--medium", 8) == 0)
			input->strategy = MEDIUM;
		else if (ft_strncmp(argv[i], "--complex", 9) == 0)
			input->strategy = COMPLEX;
		else if (ft_strncmp(argv[i], "--adaptive", 10) == 0)
			input->strategy = ADAPTIVE;
		else if (ft_strncmp(argv[i], "--bench", 7) == 0)
			input->bench = 1;
		else
			input->strategy = ERROR;
		i++;
	}
	if (i == argc)
		input->strategy = ERROR;
	input->start = i;
	input->count = argc - i;
}

int	count_args(int argc, int start)
{
	return (argc - start);
}

int	is_not_num(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	has_repeated(char **numbers)
{
	int	i;
	int	j;

	j = 0;
	while (numbers[j])
	{
		i = j + 1;
		while (numbers[i])
		{
			if ((ft_atoi(numbers[j])) == (ft_atoi(numbers[i])))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

long	ft_atol(const char *nptr)
{
	long	sign;
	long	res;
	int		i;

	sign = 1;
	res = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10 + (nptr[i] - '0'));
		i++;
	}
	return (res * sign);
}

int	in_range(char *numbers)
{
	long value;

	value = ft_atol(numbers);
	if (value > INT_MAX || value < INT_MIN)
		return (1);
	return (0);
}
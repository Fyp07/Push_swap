/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:49:16 by fbarrada          #+#    #+#             */
/*   Updated: 2026/06/19 16:42:41 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_errors(char **numbers) // Uma juncao de todas as verificacoes abaixo em uma so;
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

void	validate_flags(char **str, t_input *input) // Verifica qual estrategia esta sendo usada;
{
	int	i;

	i = 0;
	input->bench = 0;
	input->strategy = ADAPTIVE; // Comeca como ADAPTIVE por padrao;
	while (str[i] && (str[i][0] == '-' && str[i][1] == '-')) // Loop que compara as strings para alterar a estrategia;
	{
		if (ft_strncmp(str[i], "--simple", 8) == 0)
			input->strategy = SIMPLE;
		else if (ft_strncmp(str[i], "--medium", 8) == 0)
			input->strategy = MEDIUM;
		else if (ft_strncmp(str[i], "--complex", 9) == 0)
			input->strategy = COMPLEX;
		else if (ft_strncmp(str[i], "--adaptive", 10) == 0)
			input->strategy = ADAPTIVE;
		else if (ft_strncmp(str[i], "--bench", 7) == 0)
			input->bench = 1;
		else
			input->strategy = ERROR; // Se nao for valida, da erro;
		i++;
	}
	if (str[i] == NULL)
		input->strategy = ERROR;
	input->start = i;
}

int	count_args(int argc, int start) // Funcao para encontrar onde comeca os argumentos;
{
	return (argc - start);
}

int	is_not_num(char *str) // Verifica se o argumento passado nao e um numero;
{
	int	i;

	i = 0;
	if (!str[i])
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0' || str[i] == ' ')
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	has_repeated(char **numbers) // Verifica se ha numeros repetidos;
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

long	ft_atol(const char *nptr) // Atoi com long;
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

int	in_range(char *numbers) // Verifica se esta entre o int min e int max;
{
	long value;

	value = ft_atol(numbers);
	if (value > INT_MAX || value < INT_MIN)
		return (1);
	return (0);
}
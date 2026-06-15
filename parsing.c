/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:49:16 by fbarrada          #+#    #+#             */
/*   Updated: 2026/06/15 18:57:55 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_input	validate_flags(int argc, char **argv, t_input *input)
{
	int	i;

	i = 1;
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
		i++;
	}
	input->start = i;
	input->count = argc - i;
}

int	quntos_args(int argc, char *argv[], int start)
{
	return (argc - start);
}

int	is_not_a_number(int argc, char	*argv[])
{
	int	i;
	int	j;

	j = 3;
	while (j < argc)
	{
		i = 0;
		while(argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
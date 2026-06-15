/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:49:16 by fbarrada          #+#    #+#             */
/*   Updated: 2026/06/15 14:40:01 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_flags(int *argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--simple", 8) == 0)
			return (SIMPLE);
		else if (ft_strncmp(argv[i], "--medium", 8) == 0)
			return (MEDIUM);
		else if (ft_strncmp(argv[i], "--complex", 9) == 0)
			return (COMPLEX);
		else if (ft_strncmp(argv[i], "--adaptive", 10) == 0)
			return (ADAPTIVE);
	}
}

int	quntos_args(char *argv[])
{
	char	**argumentos;
	int	i;
	
	i = 0;
	argumentos = ft_split(argv, " "); // "1 4 7 85 3 1"
	while (argumentos[i])
		i++;
	return i;
}
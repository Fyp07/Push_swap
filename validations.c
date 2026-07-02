/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:24:08 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/02 12:10:03 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./Libft/libft.h"

int	processing_args(char **str, t_input *input) // Apenas uma juncao do validate flags com o check errors (valida tudo);
{
	validate_flags(str, input);
	if (input->strategy == ERROR)
		return (1);
	if (check_errors(str + input->start) == 1)
		return (1);
	return (0);
}

char	**argv_to_string(int argc, char **argv) // Pega um array de arrays, passa para um array e depois passa para um array de arrays novamente;
{
	int	i;
	char	*str;
	char	**str_split;
	int len;

	i = 0;
	len = 0;
	while (argv[i])
	{
		len += ft_strlen(argv[i]); 
		if (argv[i][0] == '\0' || (argv[i][0] == ' ' && argv[i][1] == '\0'))
			return (write(2, "Error\n", 6), exit(1), NULL);
		i++;
	}
	len += argc;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (exit(1), NULL);
	str = join(str, argv);
	str_split = ft_split(str, ' ');
	free(str);
	return (str_split);
}

char	*join(char *str, char **argv) // Junta os argumentos em uma string (usado em argv_to_string);
{
	int	i;
	int	j;
	int k;

	j = 0;
	k = 0;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			str[k] = argv[j][i];
			k++;
			i++;
		}
		str[k] = ' ';
		k++;
		j++;
	}
	
	str[k] = '\0'; 
	return (str);
}

int	ft_strcmp(char	*s1, char	*s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return(s1[i] - s2[i]);
}

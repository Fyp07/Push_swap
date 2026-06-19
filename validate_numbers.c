/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:08:49 by fbarrada          #+#    #+#             */
/*   Updated: 2026/06/19 14:06:39 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./Libft/libft.h"

int	validate_numbers(char **str, t_input *input)
{
	validate_flags(str, input);
	if (input->strategy == ERROR)
		return (1);
	if (check_errors(str + input->start) == 1)
		return (1);
	return (0);
}

char	**argv_to_string(int argc, char **argv)
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

char	*join(char *str, char **argv)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:24:08 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/13 17:31:57 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include "push_swap.h"

void	validate_flags(char **str, t_input *input)
{
	int	i;

	i = 0;
	input->count = 0;
	input->bench = 0;
	input->strategy = ADAPTIVE;
	while (str[i] && (str[i][0] == '-' && str[i][1] == '-'))
	{
		if (ft_strcmp(str[i], "--simple") == 0)
			input->strategy = SIMPLE;
		else if (ft_strcmp(str[i], "--medium") == 0)
			input->strategy = MEDIUM;
		else if (ft_strcmp(str[i], "--complex") == 0)
			input->strategy = COMPLEX;
		else if (ft_strcmp(str[i], "--adaptive") == 0)
			input->strategy = ADAPTIVE;
		else if (ft_strcmp(str[i], "--bench") == 0)
			input->bench = 1;
		else
			input->strategy = ERROR;
		i++;
	}
	if (str[i] == NULL)
		input->strategy = ERROR;
	input->start = i;
}

int	processing_args(char **str, t_input *input)
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
	int		i;
	char	*str;
	char	**str_split;
	int		len;

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
	str = join_str(str, argv);
	str_split = ft_split(str, ' ');
	free(str);
	return (str_split);
}

char	*join_str(char *str, char **argv)
{
	int	i;
	int	j;
	int	k;

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

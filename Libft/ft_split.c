/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:15:11 by fbarrada          #+#    #+#             */
/*   Updated: 2026/06/18 14:51:26 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		if (str[i] != '\0')
			words++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (words);
}

static char	**freeall(char **box, int words)
{
	int i;

	i = 0;
	while (i < words)
	{
		free(box[i]);
		i++;
	}
	free(box);
	return (NULL);
}

static char	**allocate_words(const char *str, char c, char **box)
{
	int	i;
	int	start;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		start = 0;
		while (str[i] == c)
			i++;
		if (str[i] == '\0')
			break ;
		while (str[i + start] && str[i + start] != c)
			start++;
		box[words] = malloc(sizeof(char) * start + 1);
		if (!box[words])
			return (freeall(box, words));
		start = 0;
		while (str[i] && str[i] != c)
			box[words][start++] = str[i++];
		box[words][start] = '\0';
		words++;
	}
	return (box);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**box;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	box = malloc(sizeof(char *) * (count + 1));
	if (!box)
		return (NULL);
	if (!(allocate_words(s, c, box)))
		return (NULL);
	box[count] = 0;
	return (box);
}

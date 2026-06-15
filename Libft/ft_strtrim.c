/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:08:41 by fbarrada          #+#    #+#             */
/*   Updated: 2026/05/13 18:14:37 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	check(const char *str, int character)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)character)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	slen;
	char	*newstr;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && check(set, s1[start]) == 1)
		start++;
	while (end > start && check(set, s1[end]) == 1)
		end--;
	slen = (end - start) + 1;
	newstr = (char *)malloc(slen + 1);
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1 + start, slen + 1);
	return (newstr);
}

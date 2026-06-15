/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:47:46 by fbarrada          #+#    #+#             */
/*   Updated: 2026/05/13 18:14:41 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	str = (char *)s + start;
	if (len > ft_strlen(str))
		i = ft_strlen(str) + 1;
	else
		i = len + 1;
	sub = malloc(i * sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, str, i);
	return (sub);
}

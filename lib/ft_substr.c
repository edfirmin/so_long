/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:01:34 by edfirmin          #+#    #+#             */
/*   Updated: 2023/04/04 11:45:52 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s || start == 4294967295 || ft_strlen(s) < (size_t)start)
	{
		str = malloc(1 * sizeof(char));
		str[0] = '\0';
		return (str);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc((len + 1) * sizeof(*s));
	if (!str)
		return (0);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (i >= start && j < len)
			str[j++] = s[i];
	}
	str[j] = '\0';
	return (str);
}

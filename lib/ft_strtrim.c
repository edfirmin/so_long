/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:46:37 by edfirmin          #+#    #+#             */
/*   Updated: 2023/04/06 09:07:21 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*memerro(char *str)
{
	str = malloc(1 * sizeof(char));
	str[0] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		early;
	size_t		end;
	char		*dupli;

	early = 0;
	dupli = 0;
	if (s1 == set || (!*s1 && set))
		return (memerro(dupli));
	if (s1 != 0 && set != 0)
	{
		end = ft_strlen((char *) s1);
		while (s1[early] && ft_strchr(set, s1[early]))
			early++;
		while (s1[end - 1] && ft_strchr(set, s1[end - 1]))
			end--;
		if (early >= end)
			return (ft_strdup(""));
		dupli = malloc(sizeof (char) * (end - early + 1));
		if (!dupli)
			return (0);
		if (dupli)
			ft_strlcpy(dupli, &s1[early], end - early + 1);
	}
	return (dupli);
}

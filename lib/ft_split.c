/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:07:42 by edfirmin          #+#    #+#             */
/*   Updated: 2023/04/07 09:43:03 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nb_word(char const *str, char ch)
{
	size_t	j;
	int		i;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] != ch && str[i] != '\0')
			&& (str[i + 1] == ch || str[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static int	size_word(char const *str, char ch)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] == ch && str[i])
		i++;
	while (str[i] != ch && str[i])
	{
		j++;
		i++;
	}
	return (j);
}

static char	*copy(char *dest, const char *src, char ch)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != ch)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**tab(char const *s, char c, char **tab_str)
{
	size_t	j;
	int		i;

	i = -1;
	j = 0;
	while (s[++i] && j < nb_word(s, c))
	{
		while (s[i] == c)
			i++;
		tab_str[j] = malloc((size_word(&s[i], c) + 1) * sizeof(char));
		if (!tab_str[j])
		{
			while (j-- >= 0)
				free(tab_str[j]);
			free(tab_str);
			return (0);
		}
		copy(tab_str[j], &s[i], c);
		if (s[i + size_word(&s[i], c)])
			i += size_word(&s[i], c);
		j++;
	}
	tab_str[j] = NULL;
	return (tab_str);
}

char	**ft_split(char const *s, char c)
{
	char		**tab_str;

	tab_str = (char **)malloc((nb_word(s, c) + 1) * sizeof(char *));
	if (!tab_str)
	{
		free(tab_str);
		return (0);
	}
	return (tab(s, c, tab_str));
}

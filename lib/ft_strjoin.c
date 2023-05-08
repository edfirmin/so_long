/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:29:45 by edfirmin          #+#    #+#             */
/*   Updated: 2023/04/03 12:49:58 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = -1;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	if (str)
	{
		while (s1[++j])
		{
			str[i] = s1[j];
			i++;
		}
		j = -1;
		while (s2[++j])
		{
			str[i] = s2[j];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}

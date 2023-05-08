/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 09:33:16 by edilson           #+#    #+#             */
/*   Updated: 2023/03/31 11:36:22 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*sstr;

	i = 0;
	str = (unsigned char *)s1;
	sstr = (unsigned char *)s2;
	if (n == 0 || str == sstr)
		return (0);
	while (n && (str[i] || sstr[i]))
	{
		if (str[i] != sstr[i])
			return (str[i] - sstr[i]);
		i++;
		n--;
	}
	return (0);
}

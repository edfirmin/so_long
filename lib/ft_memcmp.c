/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 09:58:56 by edilson           #+#    #+#             */
/*   Updated: 2023/04/03 12:48:23 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*sstr;

	i = 0;
	str = (unsigned char *)s1;
	sstr = (unsigned char *)s2;
	if (n == 0 || str == sstr)
		return (0);
	while (n)
	{
		if (str[i] != sstr[i])
			return (str[i] - sstr[i]);
		i++;
		n--;
	}
	return (0);
}

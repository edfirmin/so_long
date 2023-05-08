/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:16:00 by edfirmin          #+#    #+#             */
/*   Updated: 2023/03/29 16:05:32 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*str;
	char	*sstr;

	if (!dst && !src)
		return (0);
	i = 0;
	str = (char *)dst;
	sstr = (char *)src;
	while (i < n)
	{
		str[i] = sstr[i];
		i++;
	}
	return ((void *)str);
}

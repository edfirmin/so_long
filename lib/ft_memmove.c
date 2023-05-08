/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:20:37 by edfirmin          #+#    #+#             */
/*   Updated: 2023/03/31 17:25:52 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*str;
	char	*sstr;

	i = -1;
	str = (char *)dst;
	sstr = (char *)src;
	if (!src && !dst)
		return (0);
	if (str > sstr)
	{
		while (len > 0)
		{
			len--;
			str[len] = sstr[len];
		}
	}
	else
	{
		while (++i < len)
		{
			str[i] = sstr[i];
		}
	}
	return (str);
}

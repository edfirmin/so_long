/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:09:01 by edfirmin          #+#    #+#             */
/*   Updated: 2023/04/04 14:41:35 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_str(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i = 11;
		return (i);
	}
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		i++;
		n = n / 10;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				i;
	char			*str;

	i = size_str(n);
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	str = malloc(sizeof(char) * (i + 1));
	if (str == 0)
		return (0);
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

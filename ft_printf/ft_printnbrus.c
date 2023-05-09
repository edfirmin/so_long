/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbrus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:01:55 by edfirmin          #+#    #+#             */
/*   Updated: 2023/04/13 09:22:12 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_str(unsigned int n)
{
	int	i;

	i = 0;
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

int	ft_printnbrus(unsigned int nbr)
{
	if (nbr < 0)
	{
		ft_printchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_printnbr(nbr / 10);
		ft_printchar(nbr % 10 + '0');
	}
	else
		ft_printchar(nbr % 10 + '0');
	return (size_str(nbr));
}

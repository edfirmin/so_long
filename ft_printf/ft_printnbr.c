/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:51:28 by edfirmin          #+#    #+#             */
/*   Updated: 2023/04/13 11:05:52 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_printnbr(int nbr)
{
	int	size;

	size = nbr;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
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
	return (size_str(size));
}

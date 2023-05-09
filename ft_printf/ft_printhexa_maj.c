/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa_maj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:23:39 by edilson           #+#    #+#             */
/*   Updated: 2023/04/13 10:15:14 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa_maj(unsigned int n)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
	{
		i = ft_printhexa_maj(n / 16);
		ft_printchar(base[n % 16]);
	}
	else
		ft_printchar(base[(n % 16)]);
	return (i + 1);
}

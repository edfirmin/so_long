/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:18:13 by edfirmin          #+#    #+#             */
/*   Updated: 2023/04/13 11:40:30 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printadd(unsigned long int n)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		i = ft_printadd(n / 16);
		ft_printchar(base[n % 16]);
	}
	else
		ft_printchar(base[(n % 16)]);
	return (i + 1);
}

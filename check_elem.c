/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:21:21 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/09 09:30:58 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	element(char *src, char c)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	if (!src)
		return (0);
	while (src[i])
	{
		if (src[i] == c)
			j++;
		i++;
	}
	return (j);
}

void	map_elem(char *str)
{
	if (element(str, 'P') != 1)
		ft_exit(3);
	else if (element(str, 'E') != 1)
		ft_exit(2);
	else if (element(str, 'C') == 0)
		ft_exit(1);
}

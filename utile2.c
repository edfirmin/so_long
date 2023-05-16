/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:52:20 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/16 14:28:56 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	event_check(int x, int y, int n, t_img *param)
{
	if (param->smap[y][x] == '0' || param->smap[y][x] == 'C')
	{
		param->smap[y][x] = 'P';
		if (n == 1)
			param->smap[y + 1][x] = '0';
		if (n == 2)
			param->smap[y - 1][x] = '0';
		if (n == 3)
			param->smap[y][x + 1] = '0';
		if (n == 4)
			param->smap[y][x - 1] = '0';
		return (1);
	}
	if (param->smap[y][x] == 'E' && nb_colec(param->smap) == 0)
		end_mouv(param);
	return (0);
}

int	init_val(char **smap, int x, int y)
{
	y = 0;
	while (smap[y])
	{
		x = 0;
		while (smap[y][x])
		{
			if (smap[y][x] == 'P')
				break ;
			x++;
		}
		if (smap[y][x] == 'P')
			break ;
		y++;
	}
	return (x);
}

int	init_val2(char **smap, int x, int y)
{
	y = 0;
	while (smap[y])
	{
		x = 0;
		while (smap[y][x])
		{
			if (smap[y][x] == 'P')
				break ;
			x++;
		}
		if (smap[y][x] == 'P')
			break ;
		y++;
	}
	return (y);
}

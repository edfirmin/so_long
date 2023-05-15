/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:28:33 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/15 13:17:15 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	base(void *mlx_ptr, void *window, void *map, char *str)
{
	int	x;
	int	y;
	int	u;
	int	len;
	int	lon;

	len = len_cont(str);
	lon = lon_cont(str);
	u = len;
	x = 0;
	y = 0;
	while (lon > 0)
	{
		len = u;
		x = 0;
		while (len > 0)
		{
			mlx_put_image_to_window(mlx_ptr, window, map, x, y);
			x += 50;
			len--;
		}
		lon--;
		y += 50;
	}
}

void	base2(t_img ima)
{
	int	i;
	int	j;
	int	x;
	int	y;

	y = 0;
	j = 0;
	while (ima.smap[j])
	{
		i = 0;
		x = 0;
		while (ima.smap[j][i])
		{
			if (ima.smap[j][i] == '1')
				mlx_put_image_to_window(ima.mlx_ptr, ima.window,
					ima.wall, x, y);
			if (ima.smap[j][i] == 'C')
				mlx_put_image_to_window(ima.mlx_ptr, ima.window,
					ima.colec, x, y);
			x += 50;
			i++;
		}
		y += 50;
		j++;
	}
}

void	base3(t_img ima)
{
	int	i;
	int	j;
	int	x;
	int	y;

	y = 0;
	j = 0;
	while (ima.smap[j])
	{
		i = 0;
		x = 0;
		while (ima.smap[j][i])
		{
			if (ima.smap[j][i] == 'P')
				mlx_put_image_to_window(ima.mlx_ptr, ima.window,
					ima.perso, x, y);
			if (ima.smap[j][i] == 'E')
				mlx_put_image_to_window(ima.mlx_ptr, ima.window,
					ima.exit, x, y);
			x += 50;
			i++;
		}
		y += 50;
		j++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:32:52 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/16 13:17:25 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	event_check(int x, int y, int n, char **smap)
{
	if (smap[y][x] == '0' || smap[y][x] == 'C')
	{
		smap[y][x] = 'P';
		if (n == 1)
			smap[y + 1][x] = '0';
		if (n == 2)
			smap[y - 1][x] = '0';
		if (n == 3)
			smap[y][x + 1] = '0';
		if (n == 4)
			smap[y][x - 1] = '0';
		return (1);
	}
	if (smap[y][x] == 'E' && nb_colec(smap) == 0)
		return (1);
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

int	touch(int key_touch, t_img	*param)
{
	static int	x;
	static int	y;
	static int	n;

	if (!x && !y && !n)
	{
		x = init_val(param->smap, x, y);
		y = init_val2(param->smap, x, y);
		n = 1;
	}
	if (param->smap[y][x] == 'E')
		exit(0);
	if (key_touch == 13 && event_check(x, y - 1, 1, param->smap) == 1)
		y = up_mouv(param, y, n++);
	if (key_touch == 1 && event_check(x, y + 1, 2, param->smap) == 1)
		y = down_mouv(param, y, n++);
	if (key_touch == 0 && event_check(x - 1, y, 3, param->smap) == 1)
		x = left_mouv(param, x, n++);
	if (key_touch == 2 && event_check(x + 1, y, 4, param->smap) == 1)
		x = right_mouv(param, x, n++);
	if (key_touch == 53)
		exit(0);
	return (0);
}

t_img	init(t_img	ima, char *map)
{
	t_int	val;

	ima.smap = ft_split(map, '\n');
	ima.mlx_ptr = mlx_init();
	ima.window = mlx_new_window(ima.mlx_ptr, len_cont(map) * 50,
			lon_cont(map) * 50, "oui");
	ima.map = mlx_xpm_file_to_image(ima.mlx_ptr, "map.xpm",
			&val.x, &val.x);
	ima.wall = mlx_xpm_file_to_image(ima.mlx_ptr, "wall.xpm", &val.x, &val.y);
	ima.up = mlx_xpm_file_to_image(ima.mlx_ptr, "up.xpm", &val.x, &val.y);
	ima.down = mlx_xpm_file_to_image(ima.mlx_ptr, "down.xpm", &val.x, &val.y);
	ima.left = mlx_xpm_file_to_image(ima.mlx_ptr, "left.xpm", &val.x, &val.y);
	ima.right = mlx_xpm_file_to_image(ima.mlx_ptr, "right.xpm", &val.x, &val.y);
	ima.colec = mlx_xpm_file_to_image(ima.mlx_ptr, "colec.xpm", &val.x, &val.y);
	ima.exit = mlx_xpm_file_to_image(ima.mlx_ptr, "exit.xpm", &val.x, &val.y);
	return (ima);
}

int	main(int argc, char **argv)
{
	t_img	ima;
	t_int	val;

	val.fd = -1;
	ima.mapp = NULL;
	if (argc == 2)
	{
		if (ft_strstr(argv[1], ".ber"))
			val.fd = open(argv[1], O_RDONLY);
		else
			ft_exit(9);
		ima.mapp = map_check(val.fd);
	}
	else
		ft_exit(8);
	ima = init(ima, ima.mapp);
	val.n_colec = nb_colec(ima.smap);
	base(ima.mlx_ptr, ima.window, ima.map, ima.mapp);
	base2(&ima);
	base3(&ima);
	ft_printf("0\n");
	mlx_hook(ima.window, 2, 0, touch, &ima);
	mlx_loop(ima.mlx_ptr);
}

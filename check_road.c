/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_road.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:46:59 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/08 17:43:13 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_road(char **map, int x, int y)
{
	if (map[y][x] != '1' && map[y][x] != 'X')
	{
		map[y][x] = 'X';
		check_road(map, x, y - 1);
		check_road(map, x, y + 1);
		check_road(map, x - 1, y);
		check_road(map, x + 1, y);
	}
	y = 1;
	x = 1;
	// printf("%s\n", map[0]);
	// printf("%s\n", map[1]);
	// printf("%s\n", map[2]);
	// printf("%s\n", map[3]);
	// printf("%s\n", map[4]);
	while (map[y][x])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != 'X' && map[y][x] != '1')
				ft_exit();
			x++;
		}
		y++;
	}
}

void	map_road(char *str)
{
	char	**map;
	int		x;
	int		y;

	y = 0;
	x = 0;
	map = ft_split(str, '\n');
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				break ;
			x++;
		}
		if (map[y][x] == 'P')
			break ;
		y++;
	}
	printf ("x = %d,y = %d\n", x, y);
	check_road(map, x, y);
}

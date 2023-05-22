/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_road.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:46:59 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/22 13:18:50 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_road(char **map, int x, int y)
{
	if (map[y][x] != '1' && map[y][x] != 'X')
	{
		map[y][x] = 'X';
		check_road(map, x, y - 1);
		check_road(map, x, y + 1);
		check_road(map, x - 1, y);
		check_road(map, x + 1, y);
	}
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != 'X' && map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_road2(char **map, int x, int y)
{
	if (map[y][x] != '1' && map[y][x] != 'X' && map [y][x] != 'E')
	{
		map[y][x] = 'X';
		check_road2(map, x, y - 1);
		check_road2(map, x, y + 1);
		check_road2(map, x - 1, y);
		check_road2(map, x + 1, y);
	}
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != 'X' && map[y][x] != '1'
				&& map [y][x] != 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	map_road(char *str)
{
	char	**map;
	int		x;
	int		y;
	int		i;

	y = 0;
	x = 0;
	map = ft_split(str, '\n');
	x = init_val(map, x, y);
	y = init_val2(map, x, y);
	i = check_road(map, x, y);
	tab_free(map);
	map = ft_split(str, '\n');
	i += check_road2(map, x, y);
	tab_free(map);
	if (i != 2)
		ft_exit(5);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_road.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:46:59 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/11 10:46:24 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_road(char **map, int x, int y)
{
	if (map[y][x] != '1' && map[y][x] != 'X' && map[y][x] != 'E')
	{
		map[y][x] = 'X';
		check_road(map, x, y - 1);
		check_road(map, x, y + 1);
		check_road(map, x - 1, y);
		check_road(map, x + 1, y);
	}
	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != 'X' && map[y][x] != '1' && map[y][x] != 'E')
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
	i = check_road(map, x, y);
	if (i == 0)
		ft_exit(5);
}

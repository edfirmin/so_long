/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:08:45 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/09 10:27:03 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*line(char *buffer, int fd)
{
	char	*str;
	int		i;

	str = ft_calloc(2, sizeof(char));
	buffer = ft_calloc(sizeof(char), 1);
	if (!str || !buffer)
		return (ft_free(str, buffer));
	i = 1;
	while (i == 1)
	{
		ft_bzero(str, 1);
		i = read(fd, str, 1);
		if (i == 0)
			break ;
		buffer = ft_strjoin(buffer, str);
	}
	free(str);
	if (!buffer[0])
		ft_exit(0);
	return (buffer);
}

char	*map_check(int fd)
{
	char		*buffer;

	buffer = NULL;
	if (fd == -1)
		return (NULL);
	buffer = line(buffer, fd);
	map_elem(buffer);
	map_no_elem(buffer);
	map_rect(buffer);
	map_close(buffer);
	map_road(buffer);
	return (buffer);
}

int	main(int argc, char **argv)
{
	int	fd;
	//char	*map;

	fd = -1;
	if (argc == 2)
	{
		if (ft_strstr(argv[1], ".ber"))
			fd = open(argv[1], O_RDONLY);
		else
			ft_exit(9);
		map_check(fd);
	}
	else
		ft_exit(8);
}

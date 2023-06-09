/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:08:45 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/22 15:34:13 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*line(char *buffer, int fd)
{
	char	*str;
	int		i;

	str = ft_calloc(2, sizeof(char));
	if (!buffer)
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

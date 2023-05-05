/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:08:45 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/05 11:32:52 by edfirmin         ###   ########.fr       */
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

void	close_check(int line, char *src, int len)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (src[i] && src[i] != '\n')
	{
		if (src[i] != '1')
			ft_exit();
		while (src[i] == '1')
			i++;
		if (src[i] == '\n')
			i++;
		else if (src[i] != '\0')
			ft_exit();
		while (line - 2 > n)
		{
			if (src[i] == '1' && src[i + len - 1] == '1')
				i += len + 1;
			else
				ft_exit();
			n++;
		}
	}
	if (src[i] == '\0' && src[i - 1] == '1')
		printf("Map valide");
	free(src); //a virer plus tard
}

void	valide3(char *str)
{
	int	i;
	int	n;
	int	l;

	n = 1;
	l = 0;
	i = -1;
	while (str[++i] != '\n')
		l++;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	close_check(n, str, l);
}

void	valide1(char *str)
{
	if (element(str, 'P') != 1)
		ft_exit();
	else if (element(str, 'E') != 1)
		ft_exit();
	else if (element(str, 'C') == 0)
		ft_exit();
	else
		printf("%s\n", "Tout les element sont la.");
}

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
	printf("%s\n", buffer);
	return (buffer);
}

void	main_fonc(int fd)
{
	char		*buffer;

	buffer = NULL;
	if (fd == -1)
		return ;
	buffer = line(buffer, fd);
	valide1(buffer);
	valide3(buffer);
}

int	main(void)
{
	int	fd;

	fd = open("yep.ber", O_RDONLY);
	main_fonc(fd);
}

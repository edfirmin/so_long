/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_close_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:06:52 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/08 13:08:31 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

void	map_close(char *str)
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

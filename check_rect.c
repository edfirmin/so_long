/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:12:30 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/08 13:16:45 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rect(int nbofline, char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 1;
	j = 0;
	while (str[i] != '\n')
	{
		i++;
		j = i + 1;
	}
	if (i == nbofline)
		ft_exit();
	while (k < nbofline)
	{
		if (str[i] != '\n')
			ft_exit();
		i += j;
		k++;
	}
	if (str[i] != '\0')
		ft_exit();
}

void	map_rect(char *str)
{
	int	k;
	int	nbofline;

	k = 0;
	nbofline = 1;
	while (str[k])
	{
		if (str[k] == '\n')
			nbofline++;
		k++;
	}
	check_rect(nbofline, str);
}

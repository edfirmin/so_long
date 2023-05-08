/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_no_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:37:59 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/08 13:53:52 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_no_elem(char *buffer)
{
	int		i;
	int		j;
	char	**tab;

	j = 0;
	tab = ft_split(buffer, '\n');
	if (!tab)
		ft_exit();
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] != '1' && tab[j][i] != '0' && tab[j][i] != 'E'
				&& tab[j][i] != 'P' && tab[j][i] != 'C')
				ft_exit();
			i++;
		}
		j++;
	}
}

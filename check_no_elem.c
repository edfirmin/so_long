/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_no_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:37:59 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/22 13:20:45 by edilson          ###   ########.fr       */
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
		ft_exit(0);
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] != '1' && tab[j][i] != '0' && tab[j][i] != 'E'
				&& tab[j][i] != 'P' && tab[j][i] != 'C')
				ft_exit(7);
			i++;
		}
		j++;
	}
	tab_free(tab);
}

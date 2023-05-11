/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:07:46 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/11 10:43:13 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(int i)
{
	ft_printf("%s\n", "Error");
	if (i == 0)
		ft_printf("%s\n", "Map invalide !");
	if (i == 1)
		ft_printf("%s\n", "Il faut au moins un collectible sur la map !");
	if (i == 2)
		ft_printf("%s\n", "Il doit y avoir une sortie et une seule !");
	if (i == 3)
		ft_printf("%s\n", "Il doit y avoir un spawn et un seul !");
	if (i == 4)
		ft_printf("%s\n", "Map ouverte !");
	if (i == 5)
		ft_printf("%s\n", "Pas de chemin possible !");
	if (i == 6)
		ft_printf("%s\n", "La map n'est pas rectengulaire !");
	if (i == 7)
		ft_printf("%s\n", "Element inconnu");
	if (i == 8)
		ft_printf("%s\n", "Nombre d'argument invalide !");
	if (i == 9)
		ft_printf("%s\n", "La map doit être un fichier '.ber' !");
	exit(0);
}

void	*ft_free(char *str1, char *str2)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (NULL);
}

int	len_cont(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int	lon_cont(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i])
	{
		if (str[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

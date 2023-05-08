/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:07:46 by edfirmin          #+#    #+#             */
/*   Updated: 2023/05/08 09:14:04 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(void)
{
	printf("%s\n", "Error");
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

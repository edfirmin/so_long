/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:45:20 by edfirmin          #+#    #+#             */
/*   Updated: 2023/04/08 12:45:33 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tempo;

	tempo = *lst;
	if (*lst)
	{
		while (tempo->next)
			tempo = tempo->next;
		tempo->next = new;
	}
	else
		*lst = new;
}

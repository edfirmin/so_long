/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:46:33 by edfirmin          #+#    #+#             */
/*   Updated: 2023/04/08 12:46:40 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tempo;
	t_list	*tempo2;

	tempo = *lst;
	if (*lst)
	{
		while (tempo)
		{
			tempo2 = tempo->next;
			del(tempo->content);
			free(tempo);
			tempo = tempo2;
		}
		*lst = NULL;
	}
}

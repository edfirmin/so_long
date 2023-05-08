/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:48:00 by edfirmin          #+#    #+#             */
/*   Updated: 2023/04/08 12:48:03 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*out;

	if (!lst)
		return (NULL);
	out = NULL;
	while (lst)
	{
		list = ft_lstnew(f(lst->content));
		if (!list)
		{
			ft_lstclear(&out, del);
			return (NULL);
		}
		ft_lstadd_back(&out, list);
		lst = lst->next;
	}
	return (out);
}

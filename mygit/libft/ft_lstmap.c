/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:08:27 by flee              #+#    #+#             */
/*   Updated: 2021/06/14 14:56:24 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*previous;
	t_list	*new;

	begin = NULL;
	previous = NULL;
	if (lst)
	{
		while (lst)
		{
			new = ft_lstnew((*f)(lst->content));
			if (!new)
			{
				ft_lstclear(&begin, del);
				return (NULL);
			}
			if (!begin)
				begin = new;
			if (previous)
				previous->next = new;
			previous = new;
			lst = lst->next;
		}
	}
	return (begin);
}

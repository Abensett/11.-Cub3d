/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:37:26 by flee              #+#    #+#             */
/*   Updated: 2021/06/14 14:55:33 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*memory;

	tmp = *lst;
	while (tmp)
	{
		memory = tmp->next;
		tmp->next = NULL;
		if (tmp->content)
			(*del)(tmp->content);
		free(tmp);
		tmp = memory;
	}
	*lst = NULL;
}

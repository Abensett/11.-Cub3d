/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_popTab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:07:57 by flee              #+#    #+#             */
/*   Updated: 2022/05/06 15:07:58 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_popTab(char **tab, int i)
{
	int 	size;
	char	**pop;
	int		a;

	size = ft_size(tab);
	pop = malloc(sizeof(char *) * (size - i + 1));
	if (!pop)
		return (NULL);
	a = 0;
	while (i < size)
	{
		pop[a] = ft_strdup(tab[i]);
		i++;
		a++;
	}
	pop[a] = 0;
	ft_free_tab(tab);
	return (pop);
}
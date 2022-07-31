/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:06:16 by flee              #+#    #+#             */
/*   Updated: 2021/06/25 15:10:40 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	int		len1;
	int		len2;
	int		i;

	i = -1;
	tab = NULL;
	if (s)
	{
		len1 = (int)ft_strlen(s);
		len2 = len;
		if ((int)start > len1)
			len2 = 0;
		else if ((int)start + len2 > len1)
			len2 = len1 - (int)start;
		tab = (char *) malloc(sizeof(char) * (len2 + 1));
		if (!tab)
			return (NULL);
		while (++i < len2)
			tab[i] = s[start + i];
		tab[i] = '\0';
	}
	return (tab);
}

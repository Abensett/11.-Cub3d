/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:24:28 by flee              #+#    #+#             */
/*   Updated: 2021/06/24 11:06:44 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		cmpt1;
	int		cmpt2;
	char	*str;

	if (s1 && s2)
	{
		cmpt1 = ft_strlen((char *)s1);
		cmpt2 = cmpt1 + ft_strlen((char *)s2);
		str = (char *)malloc(sizeof(char) * (cmpt2 + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str, (char *)s1, cmpt1 + 1);
		ft_strlcat(str, (char *)s2, cmpt2 + 1);
		return (str);
	}
	return (NULL);
}

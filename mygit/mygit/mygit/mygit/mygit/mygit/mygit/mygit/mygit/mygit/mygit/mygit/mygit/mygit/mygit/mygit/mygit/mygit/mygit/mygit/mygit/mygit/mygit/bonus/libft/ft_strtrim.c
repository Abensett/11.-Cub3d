/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:19:49 by flee              #+#    #+#             */
/*   Updated: 2021/06/27 10:09:46 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charset(char const s1, char const *sep)
{
	int	index;

	index = 0;
	while (sep[index] != '\0')
	{
		if (sep[index] == s1)
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *sep)
{
	unsigned int	start;
	size_t			len;
	char			*new;

	if (s1)
	{
		start = 0;
		len = ft_strlen(s1) - 1;
		while (ft_charset(s1[start], sep))
		{
			start++;
			if (s1[start] == '\0')
				return (ft_substr(s1, 0, 0));
		}
		while (ft_charset(s1[len], sep))
			len--;
		if (len < start)
			return (NULL);
		if (s1[start] == s1[len])
			return (ft_substr(s1, 0, 0));
		new = ft_substr(s1, start, ((len - start) + 1));
		return (new);
	}
	return ((char *)s1);
}

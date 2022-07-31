/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:04:41 by flee              #+#    #+#             */
/*   Updated: 2021/06/08 14:12:54 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	index;
	unsigned long	j;

	index = 0;
	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	while (index < len && haystack[index] != '\0')
	{
		j = 0;
		while (haystack[index + j] == needle[j] && (index + j) < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack + index);
		}
		index++;
	}
	return (NULL);
}

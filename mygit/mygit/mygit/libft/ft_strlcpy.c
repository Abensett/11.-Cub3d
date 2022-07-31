/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:59:54 by flee              #+#    #+#             */
/*   Updated: 2021/06/24 10:59:15 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	int				src_len;

	i = 0;
	src_len = 0;
	if (src)
	{
		while (src[src_len])
			src_len++;
		if (size > 0)
		{
			while (src[i] && (i < (size - 1)))
			{
				dest[i] = src[i];
				i++;
			}
			dest[i] = '\0';
		}
	}
	return (src_len);
}

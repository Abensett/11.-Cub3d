/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:59:30 by flee              #+#    #+#             */
/*   Updated: 2021/06/24 21:31:11 by cesco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t destlen;
	size_t srclen;
	size_t index;

	destlen = 0;
	srclen = ft_strlen(src);
	index = 0;
	while (dst[destlen] && destlen < size)
		destlen++;
	while ((src[index]) && ((destlen + index + 1) < size))
	{
		dst[destlen + index] = src[index];
		index++;
	}
	if (destlen != size)
		dst[destlen + index] = '\0';
	return (destlen + srclen);
}
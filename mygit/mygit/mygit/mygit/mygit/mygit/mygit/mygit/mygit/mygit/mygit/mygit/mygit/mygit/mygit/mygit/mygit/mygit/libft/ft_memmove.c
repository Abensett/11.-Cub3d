/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <flee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:30:21 by flee              #+#    #+#             */
/*   Updated: 2021/06/24 13:44:51 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t				i;
	unsigned char		*dest1;
	const unsigned char	*src1;

	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	if (!dest1 && !src1)
		return (dest);
	i = 0;
	if (src1 < dest1)
		while (++i <= size)
			dest1[size - i] = src1[size - i];
	else
		while (size-- > 0)
			*(dest1++) = *(src1++);
	return (dest);
}

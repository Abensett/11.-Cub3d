/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <flee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:00:59 by flee              #+#    #+#             */
/*   Updated: 2021/06/10 14:21:03 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t si)
{
	char			*a;
	char			*b;
	unsigned long	index;

	a = (char *)s;
	b = (char *)d;
	index = 0;
	while (index < si)
	{
		b[index] = a[index];
		if ((unsigned char)b[index] == (unsigned char)c)
		{
			return ((char *)b + index + 1);
		}
		index++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:49:46 by flee              #+#    #+#             */
/*   Updated: 2021/06/10 12:35:40 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	char			*memory;
	char			needle;
	unsigned long	index;

	memory = (char *)memoryBlock;
	needle = (char)searchedChar;
	index = 0;
	while (index < size)
	{
		if (memory[index] == needle)
		{
			return (memory + index);
		}
		index++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:26:08 by flee              #+#    #+#             */
/*   Updated: 2021/06/10 12:34:57 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char			*memory;
	unsigned long	index;

	memory = malloc(elementSize * elementCount);
	index = 0;
	if (!memory)
		return (NULL);
	while (index < elementCount * elementSize)
	{
		memory[index] = 0;
		index++;
	}
	return (memory);
}

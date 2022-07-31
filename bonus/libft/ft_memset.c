/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:03:43 by flee              #+#    #+#             */
/*   Updated: 2021/06/10 14:22:33 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned long	index;
	unsigned char	*memory;
	unsigned char	value;

	index = 0;
	memory = str;
	value = c;
	while (index < n)
	{
		memory[index] = value;
		index++;
	}
	memory[index] = '\0';
	return (memory);
}

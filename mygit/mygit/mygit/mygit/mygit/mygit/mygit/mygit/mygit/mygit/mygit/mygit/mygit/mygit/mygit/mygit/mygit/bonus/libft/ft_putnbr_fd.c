/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:49:41 by flee              #+#    #+#             */
/*   Updated: 2021/06/10 11:52:41 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	a;

	a = n;
	if (a < 0)
	{
		ft_putchar_fd('-', fd);
		a = -a;
	}
	if (a > 9)
	{
		ft_putnbr_fd(a / 10, fd);
		ft_putnbr_fd(a % 10, fd);
	}
	else
	{
		ft_putchar_fd(a + '0', fd);
	}
}

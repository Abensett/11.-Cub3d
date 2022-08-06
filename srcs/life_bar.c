/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:36:38 by abensett          #+#    #+#             */
/*   Updated: 2022/08/06 17:41:51 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	my_mlx_pixel_get(t_img *image, int x, int y, int *color)
{
	char	*dst;

	dst = image->addr +
		(y * image->line_l + x * (image->byte_p / 8));
	*color = *(unsigned int*)dst;
}

void	ft_life_bar(t_game *game, int width)
{
	int		i;
	int		j;
	int		color;

	j = WINDOWS_Y - 200;
	while (j < WINDOWS_Y - 100)
	{
		i = WINDOWS_X - 200;
		while (i < WINDOWS_X -100)
		{
			color = (i - WINDOWS_X - 200 < 5 * (100 / 100))
				? 0x9F0000 : 0xFFFFFF;
			my_mlx_pixel_put(&game->windows, i++, j, color);
		}
		j++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:36:38 by abensett          #+#    #+#             */
/*   Updated: 2022/08/06 17:33:28 by abensett         ###   ########.fr       */
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

void	ft_life_bar(t_game *game, int offset_x, int offset_y, int width)
{
	int		i;
	int		j;
	int		color;

	if (offset_x < 0)
		offset_x = WINDOWS_Y + offset_x - width;
	if (offset_y < 0)
		offset_y = WINDOWS_X + offset_y - width / 10;
	j = offset_y;
	while (j < offset_y + width / 10)
	{
		i = offset_x;
		while (i < offset_x + width)
		{
			color = (i - offset_x < 5 * (width / 100))
				? 0x9F0000 : 0xFFFFFF;
			my_mlx_pixel_put(game->img, i, j, color);
		}
		j++;
	}
}

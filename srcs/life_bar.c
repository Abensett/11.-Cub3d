/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:36:38 by abensett          #+#    #+#             */
/*   Updated: 2022/08/06 17:26:26 by abensett         ###   ########.fr       */
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

void	ft_draw_heart(t_game *game, int hp)
{
	int	trgb;
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	x = game->ray.ray_dir_x - (hp * (game->ray.ray_dir_x / 14));
	if (game->ray.ray_dir_x <= 8 || game->ray.ray_dir_y <= 8)
		return ;
	while (++i < 100)
	{
		j = -1;
		x += 1;
		y = game->ray.ray_dir_y / 34;
		while (++j < 100)
		{
			my_mlx_pixel_get(game->lifebar.img, i ,
								j , &trgb);
			if ((trgb & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(&game->windows, x, y, trgb);
			y++;
		}
	}
}

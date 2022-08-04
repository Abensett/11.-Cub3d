/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:42:00 by abensett          #+#    #+#             */
/*   Updated: 2022/08/04 19:08:21 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int		apply_shadow(double dist, int *color)
{
	int transparency;

	printf("%d 1\n", color);
	transparency = (int)fmin(((*color >> 24) + 0.1) * (dist * 600), 255);
	*color = (transparency << 24 | *color);
	printf("%d 2\n", color);
	return (*color);
}

void	draw_sky_2(t_game *game, int y)
{
	int	x;

	x = 0;
	while (x < WINDOWS_X)
	{
		game->ray.cell_x = (int)(game->ray.floor_x);
		game->ray.cell_y = (int)(game->ray.floor_y);
		game->ray.tex_x = (int)(TEX_SIZE * (game->ray.floor_x
					- game->ray.cell_x)) & (TEX_SIZE - 1);
		game->ray.tex_y = (int)(TEX_SIZE * (game->ray.floor_y
					- game->ray.cell_y)) & (TEX_SIZE - 1);
		game->ray.floor_x += game->ray.floor_step_x;
		game->ray.floor_y += game->ray.floor_step_y;
		
		my_mlx_pixel_put(&game->windows, x, y,
			apply_shadow(game->ray.perp_wall_dist ,
			img_pix_get(&game->sky, game->ray.tex_x, game->ray.tex_y)));
		my_mlx_pixel_put(&game->windows, x, WINDOWS_Y - y - 1,
		apply_shadow(game->ray.perp_wall_dist ,
		 img_pix_get(&game->floor, game->ray.tex_x,
			 game->ray.tex_y)));
		x++;
	}
}

void	draw_sky(t_game *game, int y)
{
	game->ray.ray_dir_x0 = game->player.dir_x - game->player.plane_x;
	game->ray.ray_dir_x1 = game->player.dir_x + game->player.plane_x;
	game->ray.ray_dir_y0 = game->player.dir_y - game->player.plane_y;
	game->ray.ray_dir_y1 = game->player.dir_y + game->player.plane_y;
	game->ray.position = y - WINDOWS_Y / 2;
	game->ray.pos_z = 0.5 * WINDOWS_Y;
	game->ray.row_distance = game->ray.pos_z / game->ray.position;
	game->ray.floor_step_x = game->ray.row_distance * (game->ray.ray_dir_x1
			- game->ray.ray_dir_x0) / WINDOWS_X;
	game->ray.floor_step_y = game->ray.row_distance * (game->ray.ray_dir_y1
			- game->ray.ray_dir_y0) / WINDOWS_X;
	game->ray.floor_x = game->player.pos_x + game->ray.row_distance
		* game->ray.ray_dir_x0;
	game->ray.floor_y = game->player.pos_y + game->ray.row_distance
		* game->ray.ray_dir_y0;
	draw_sky_2(game, y);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:28:37 by flee              #+#    #+#             */
/*   Updated: 2022/08/08 02:39:19 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	ray_init(t_game *game, int x)
{
	double	w;

	w = WINDOWS_X;
	game->ray.camera_x = 2 * x / w - 1;
	game->ray.ray_dir_x = game->player.dir_x
		+ game->player.plane_x * game->ray.camera_x;
	game->ray.ray_dir_y = game->player.dir_y
		+ game->player.plane_y * game->ray.camera_x;
	game->ray.map_x = (int)game->player.pos_x;
	game->ray.map_y = (int)game->player.pos_y;
	if (game->ray.ray_dir_x == 0)
		game->ray.delta_dist_x = 1e30;
	else
		game->ray.delta_dist_x = fabs(1 / game->ray.ray_dir_x);
	if (game->ray.ray_dir_y == 0)
		game->ray.delta_dist_y = 1e30;
	else
		game->ray.delta_dist_y = fabs(1 / game->ray.ray_dir_y);
	game->ray.hit = 0;
}

void	ray_side_dist(t_game *game)
{
	if (game->ray.ray_dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist_x = (game->player.pos_x - game->ray.map_x)
			* game->ray.delta_dist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist_x = (game->ray.map_x + 1.0 - game->player.pos_x)
			* game->ray.delta_dist_x;
	}
	if (game->ray.ray_dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist_y = (game->player.pos_y - game->ray.map_y)
			* game->ray.delta_dist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist_y = (game->ray.map_y + 1.0 - game->player.pos_y)
			* game->ray.delta_dist_y;
	}
}

void	ray_hit(t_game *game)
{
	while (game->ray.hit == 0)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->map.map[game->ray.map_x][game->ray.map_y] == '1')
			game->ray.hit = 1;
	}
	if (game->ray.side == 0)
		game->ray.perp_wall_dist = (game->ray.side_dist_x
				- game->ray.delta_dist_x);
	else
		game->ray.perp_wall_dist = (game->ray.side_dist_y
				- game->ray.delta_dist_y);
}

void	ray_draw(t_game *game)
{
	int	h;

	h = WINDOWS_Y;
	game->ray.line_height = (int)(h / game->ray.perp_wall_dist);
	game->ray.draw_start = -game->ray.line_height / 2 + h / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	game->ray.draw_end = game->ray.line_height / 2 + h / 2;
	if (game->ray.draw_end >= h || game->ray.draw_end < 0)
		game->ray.draw_end = h;
	if (game->ray.side == 0)
		game->ray.wall_x = game->player.pos_y + game->ray.perp_wall_dist
			* game->ray.ray_dir_y;
	else
		game->ray.wall_x = game->player.pos_x + game->ray.perp_wall_dist
			* game->ray.ray_dir_x;
	game->ray.wall_x -= floor((game->ray.wall_x));
	game->ray.tex_x = (int)(game->ray.wall_x * (double)TEX_SIZE);
	if (game->ray.side == 0 && game->ray.ray_dir_x > 0)
		game->ray.tex_x = TEX_SIZE - game->ray.tex_x - 1;
	if (game->ray.side == 1 && game->ray.ray_dir_y < 0)
		game->ray.tex_x = TEX_SIZE - game->ray.tex_x - 1;
	game->ray.step = 1.0 * TEX_SIZE / game->ray.line_height;
	game->ray.tex_pos = (game->ray.draw_start
			- h / 2 + game->ray.line_height / 2) * game->ray.step;
}

void	raycasting(t_game *game)
{
	int	x;

	x = 0;
	while (x < WINDOWS_Y)
		draw_sky(game, x++);
	x = 0;
	while (x < WINDOWS_X)
	{
		ray_init(game, x);
		ray_side_dist(game);
		ray_hit(game);
		ray_draw(game);
		verline(game, x++, 0);
	}
	draw_mini_map(game, 0);
	ft_life_bar(game);
	ft_gun(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.windows,
		game->windows.img, 0, 0);
	mlx_string_put(game->mlx.mlx, game->mlx.windows, 50, 50, 0xFF0000, "Minimap");
	if (game->life <= 40)
		mlx_string_put(game->mlx.mlx, game->mlx.windows,  WINDOWS_X - 375, 70,
		 0xFF00000, "You're about to die !");
	game->shotornot = 0;
}

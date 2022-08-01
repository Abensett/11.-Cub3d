/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:28:50 by flee              #+#    #+#             */
/*   Updated: 2022/08/01 02:48:32 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

unsigned int	img_pix_get(t_img *img, int x, int y)
{
	char	*pixel;
	char	*pixel1;
	char	*pixel2;

	pixel = img->addr + (y * img->line_l + x * (img->byte_p / 8));
	pixel1 = img->addr + (y * img->line_l + x * (img->byte_p / 8));
	pixel2 = img->addr + (y * img->line_l + x * (img->byte_p / 8));
	pixel1++;
	pixel += 2;
	return ((*(int *)pixel << 16 | *(int *)pixel1 << 8 | *(int *)pixel2));
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_l + x * (data->byte_p / 8));
	*(unsigned int *)dst = color;
}

void	put_tex(t_game *game, int x)
{
	if (game->ray.side == 0 && game->ray.map_x >= game->player.pos_x)
		my_mlx_pixel_put(&game->windows, x, game->ray.draw_start,
			img_pix_get(&game->north, game->ray.tex_x, game->ray.tex_y));
	else if (game->ray.side == 0 && game->ray.map_x <= game->player.pos_x)
		my_mlx_pixel_put(&game->windows, x, game->ray.draw_start,
			img_pix_get(&game->south, game->ray.tex_x, game->ray.tex_y));
	else if (game->ray.side == 1 && game->ray.map_y <= game->player.pos_y)
		my_mlx_pixel_put(&game->windows, x, game->ray.draw_start,
			img_pix_get(&game->west, game->ray.tex_x, game->ray.tex_y));
	else if (game->ray.side == 1 && game->ray.map_y >= game->player.pos_y)
		my_mlx_pixel_put(&game->windows, x, game->ray.draw_start,
			img_pix_get(&game->east, game->ray.tex_x, game->ray.tex_y));
}

void	verline(t_game *game, int x, int sky)
{

	while (game->ray.draw_start < game->ray.draw_end)
	{
		game->ray.tex_y = (int)game->ray.tex_pos & (TEX_SIZE - 1);
		game->ray.tex_pos += game->ray.step;
		put_tex(game, x);
		game->ray.draw_start++;
	}
	(void)sky;
}

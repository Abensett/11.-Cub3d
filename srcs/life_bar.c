/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:36:38 by abensett          #+#    #+#             */
/*   Updated: 2022/08/08 00:35:11 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int 	load_texture(t_game *game, t_img *texture, char *filename)
{
	if (!(texture->img = mlx_xpm_file_to_image(game->mlx.mlx,
		filename, &texture->width, &texture->height)))
		return (0);
	if (!(texture->addr = mlx_get_data_addr(texture->img, &texture->byte_p,
		&texture->line_l, &texture->end)))
		return (0);
	return (1);
}
int		my_tex_color(t_img tex, double u, double v, double shadow)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	char			*ptr;

	shadow = (shadow > 1) ? 1 : shadow;
	shadow = (shadow < 0.4) ? 0.4 : shadow;
	ptr = tex.addr + (int)(v * tex.height) * tex.line_l
		+ (int)(u * tex.width) * (tex.byte_p >> 3);
	r = shadow * (unsigned char)(tex.end ? *ptr : *(ptr + 2));
	g = shadow * (unsigned char)(*(ptr + 1));
	b = shadow * (unsigned char)(tex.end ? *(ptr + 2) : *ptr);
	return ((r << 16) + (g << 8) + b);
}

void	ft_life_bar(t_game *game)
{
	int		i;
	int		j;
	int		color;
	int 	position[2];

	position[0] = WINDOWS_X / 2;
	position[1] = WINDOWS_Y / 2;
	j = 50;
	while (j < 75)
	{
		i = WINDOWS_X - 400;
		while (i < WINDOWS_X - 100)
		{
			color = (i - WINDOWS_X + 400 - game->life * 3 < 0)
				? 0x9F0000 : 0xFFFFFF;
			my_mlx_pixel_put(&game->windows, i++, j, color);
		}
		j++;
	}
	if (game->life <= 30)
	{
		printf("%d\n", game->life);
		write_on_screen(game, "You are dying", position, 0x000000);
	}
}

void	ft_gun(t_game *game)
{
	int		i;
	int		j;
	int		color;


	i = 0.4 * WINDOWS_X;
	while (i < 0.8 * WINDOWS_X)
	{
		j = 0.6 *  WINDOWS_Y;
		while (j + game->gun_shift <  WINDOWS_Y)
		{
			color = my_tex_color(game->gun[game->shotornot],
				((i - 0.4 * WINDOWS_X) / (0.4 * WINDOWS_X)),
				((j - 0.6 *  WINDOWS_Y) / (0.4 * WINDOWS_Y)), 1);
			if (color != 0)
				my_mlx_pixel_put(&game->windows, i, j + game->gun_shift, color);
			j++;
		}
		i++;
	}
	game->gun_shift = game->gun_shift + (game->gun_dir ? -1 : 1);
	if (game->shotornot)
		game->gun_shift = 5;
	if (game->gun_shift < 0)
		game->gun_dir = 0;
	else if (game->gun_shift > 0.05 * WINDOWS_Y)
		game->gun_dir = 1;
	game->gun_shift = (game->gun_shift < 0) ? 0 : game->gun_shift;
}
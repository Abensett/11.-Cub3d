/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:36:38 by abensett          #+#    #+#             */
/*   Updated: 2022/08/10 01:08:15 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	load_texture(t_game *game, t_img *texture, char *filename)
{
	texture->img = mlx_xpm_file_to_image(game->mlx.mlx,
			filename, &texture->width, &texture->height);
	if (!(texture->img))
		return (0);
	texture->addr = mlx_get_data_addr(texture->img, &texture->byte_p,
			&texture->line_l, &texture->end);
	if (!(texture->addr))
		return (0);
	return (1);
}

int	my_tex_color(t_img tex, double u, double v, double shadow)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	char			*ptr;

	if (shadow > 1)
		shadow = 1;
	else if (shadow < 0.4)
		shadow = 0.4;
	ptr = tex.addr + (int)(v * tex.height)*tex.line_l
		+ (int)(u * tex.width)*(tex.byte_p >> 3);
	if (tex.end)
	{
		r = shadow * (unsigned char)(*ptr);
		b = shadow * (unsigned char)(*(ptr + 2));
	}
	else
	{
		r = shadow * (unsigned char)(*(ptr + 2));
		b = shadow * (unsigned char)(*ptr);
	}
	g = shadow * (unsigned char)(*(ptr + 1));
	return ((r << 16) + (g << 8) + b);
}

void	ft_life_bar(t_game *game)
{
	int		i;
	int		j;
	int		color;

	j = 50;
	while (j < 75)
	{
		i = WINDOWS_X - 400;
		while (i < WINDOWS_X - 100)
		{
			if (i - WINDOWS_X + 400 - game->life * 3 < 0)
				color = 0x9F0000;
			else
				color = 0xFFFFFF;
			if (game->life < 30)
				if (color == 0xFFFFFF)
					color = 0xFAB7B7;
			my_mlx_pixel_put(&game->windows, i++, j, color);
		}
		j++;
	}
}

static void	ft_gun_2(t_game *game)
{
	int		cursor;

	if (game->gun_dir)
		game->gun_shift = game->gun_shift - 1;
	else
		game->gun_shift = game->gun_shift + 1;
	if (game->shotornot)
		game->gun_shift = 10;
	if (game->gun_shift < 0)
		game->gun_dir = 0;
	else if (game->gun_shift > 0.05 * WINDOWS_Y)
		game->gun_dir = 1;
	if (game->gun_shift < 0)
		game->gun_shift = 0;
	cursor = 0;
	while (cursor < 20)
		my_mlx_pixel_put(&game->windows, WINDOWS_X / 2 - 10 + cursor++,
			WINDOWS_Y / 2, 0xFF0000);
	cursor = 0;
	while (cursor < 20)
		my_mlx_pixel_put(&game->windows, WINDOWS_X / 2,
			WINDOWS_Y / 2 - 10 + cursor++, 0xFF0000);
}

void	ft_gun(t_game *game)
{
	int		i;
	int		j;
	int		color;

	i = 0.4 * WINDOWS_X;
	while (i < 0.8 * WINDOWS_X)
	{
		j = 0.6 * WINDOWS_Y;
		while (j + game->gun_shift < WINDOWS_Y)
		{
			color = my_tex_color(game->gun[game->shotornot],
					((i - 0.4 * WINDOWS_X) / (0.4 * WINDOWS_X)),
					((j - 0.6 * WINDOWS_Y) / (0.4 * WINDOWS_Y)), 1);
			if (color != 0)
				my_mlx_pixel_put(&game->windows, i, j + game->gun_shift, color);
			j++;
		}
		i++;
	}
	ft_gun_2(game);
}

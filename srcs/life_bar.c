/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:36:38 by abensett          #+#    #+#             */
/*   Updated: 2022/08/06 21:31:08 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	write_text(t_game *game, int pos[2], char *text, int color)
{
	int		x;
	int		y;

	x = pos[0] - ft_strlen(text) * 5;
	y = pos[1];
	mlx_string_put(game->mlx.mlx, game->mlx.windows, x, y, color, text);
}

int		get_tex_color(t_img tex, double u, double v, double darken)
{
	char			*ptr;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	darken = (darken > 1) ? 1 : darken;
	darken = (darken < 0.4) ? 0.4 : darken;
	ptr = tex.addr + (int)(v * tex.byte_p) * tex.line_l
		+ (int)(u * tex.byte_p) * (tex.byte_p >> 3);
	r = darken * (unsigned char)(tex.end ? *ptr : *(ptr + 2));
	g = darken * (unsigned char)(*(ptr + 1));
	b = darken * (unsigned char)(tex.end ? *(ptr + 2) : *ptr);
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
			color = (i - WINDOWS_X + 400 - game->life * 3 < 0)
				? 0x9F0000 : 0xFFFFFF;
			my_mlx_pixel_put(&game->windows, i++, j, color);
		}
		j++;
	}
}

void	ft_gun(t_game *game, int shooting)
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
			color = get_tex_color(game->gun,
				((i - 0.4 * WINDOWS_X) / (0.4 * WINDOWS_X)),
				((j - 0.6 * WINDOWS_Y) / (0.4 *WINDOWS_Y)), 1);
			if (color != 0)
				my_mlx_pixel_put(&game->windows, i, j + game->gun_shift, color);
			j++;
		}
		i++;
	}
	game->gun_shift = game->gun_shift + (game->gun_dir ? -5 : 5);
	if (game->gun_shift < 0)
		game->gun_dir = 0;
	else if (game->gun_shift > 0.05 *WINDOWS_Y)
		game->gun_dir = 1;
	game->gun_shift = (game->gun_shift < 0) ? 0 : game->gun_shift;
	shooting(* void);
}
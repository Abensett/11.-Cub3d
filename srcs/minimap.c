/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 04:22:44 by abensett          #+#    #+#             */
/*   Updated: 2022/08/01 04:28:51 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_square(t_game *game, int i, int j, int color)
{
	int	x;
	int	y;

	x = WINDOWS_Y * 0.005 * j;
	y = WINDOWS_Y * 0.005 * i;
	while (x < WINDOWS_Y * 0.005 * (j + 1))
	{
		y = WINDOWS_Y * 0.005 * i;
		while (y < WINDOWS_Y * 0.005 * (i + 1))
		{
			my_mlx_pixel_put(&game->windows, x, y, color);
			y++;
		}
		x++;
	}
}

static void	draw_player(t_game *game, int color)
{
	draw_square(game, game->player.pos_y, game->player.pos_x, color);
}

void	draw_mini_map(t_game *game, int color)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j] != '\0')
		{
			if (game->map.map[i][j] == '1')
				draw_square(game, i, j, color);
			else if (game->map.map[i][j] == ' ')
			{
				j++;
				continue ;
			}
			else
				draw_square(game, i, j, 0x808080);
			j++;
		}
		i++;
	}
	draw_player(game, 65280);
}
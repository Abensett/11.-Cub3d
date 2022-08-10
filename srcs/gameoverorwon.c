/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameoverorwon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 00:05:30 by abensett          #+#    #+#             */
/*   Updated: 2022/08/10 04:00:29 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

// write the text at pos[2] with color
void	write_on_screen(t_game *game, char *text, int pos[2], int color)
{
	int		x;
	int		y;

	x = pos[0] - ft_strlen(text) * 5;
	y = pos[1];
	mlx_string_put(game->mlx.mlx, game->mlx.windows, x, y, color, text);
}

// check if the game is won or not
void 	check_dead_win(t_game *game)
{
	load_texture(game, &game->game_over, "./img/gameover.xpm");
	if(game->life < 0)
	{
		if (game->life <= -70)
		{
			system("cvlc --play-and-exit img/lost.mp3 &>/dev/null &");
			wait(7);
			free_and_destroy(game);
		}
		system("killall -9 vlc");
			mlx_put_image_to_window(game->mlx.mlx, game->mlx.windows,
		game->game_over.img, 0, -150);
		game->life = -70;
	}
	else if (game->won)
	{
		system("killall -9 vlc");
		system("cvlc --play-and-exit img/win.mp3 &>/dev/null &");
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.windows,
		game->windows.img, 0, 0);
	}
	else
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.windows,
		game->windows.img, 0, 0);
	
}
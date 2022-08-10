/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:54:15 by flee              #+#    #+#             */
/*   Updated: 2022/08/10 03:18:13 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	render_next_frame(t_game *game)
{
	raycasting(game);
	return (1);
}

int	color_get(t_img *img, int x, int y)
{
	int	rep;
	int	ret;

	rep = (x * img->line_l) / 4 + y;
	ret = create_rgb(img->addr[rep], img->addr[rep + 1], img->addr[rep + 2]);
	return (ret);
}

void	ft_handle_shoot(t_game *game)
{
	if (game->bullets >= 0 && game->shotornot < 2) 
	{
		system("cvlc --play-and-exit img/gun_shot2.mp3 &>/dev/null &");
		game->bullets--;
	}
	else
		system("cvlc --play-and-exit img/knife.mp3 &>/dev/null &");
	i = game->nb_sprites;

	while (i > 0)
	{
		if (game->sprites[i].alive)
		{
			game->map.map[game->sprites[i].pos[0]][game->sprites[i].pos[1]] = '0';
			game->sprites[i].dead = 1;
			break ;
		}
		i--;
	}
	game->shotornot++;
}

int	ft_handle_mouse(int button, int x, int y, t_game *game)
{
	static int	weapon = 0;
	
	x++;
	y++;

	if (button == 3)
	{
		if (weapon++ == 0)
		{
			game->shotornot = 2;
		}
		else
		{
			game->shotornot = 0;
			weapon = 0;
		}
	}
	
	return (0);
}

/* **************************************************************************
open_img -> open texture files
hooks ->(window, number = event, mask = key pressed or not etc, fcn, param)
		 1L<<0 key pressed
		1L<<2 key released
		1L<<5 Leave window
*****************************************************************************/
void	game_loop(t_game *game)
{
	game->mlx.mlx = mlx_init();
	game->mlx.windows = mlx_new_window(game->mlx.mlx,
			WINDOWS_X, WINDOWS_Y, "Cub3d bonus");
	open_img(game);
	mlx_loop_hook(game->mlx.mlx, &render_next_frame, game);
	mlx_hook(game->mlx.windows, 2, 1L << 0, input, game);
	mlx_hook(game->mlx.windows, 3, 1L << 1, exput, game);
	mlx_hook(game->mlx.windows, 33, 1l << 5, free_and_destroy, game);
	mlx_mouse_hook(game->mlx.windows, &ft_handle_mouse, game);
	mlx_loop(game->mlx.mlx);
}

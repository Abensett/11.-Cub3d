/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:54:15 by flee              #+#    #+#             */
/*   Updated: 2022/08/08 11:23:47 by abensett         ###   ########.fr       */
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
	system("cvlc --play-and-exit img/gun_shot2.mp3 &>/dev/null &");
	if (game->bullets >= 0)
	{
		game->shotornot = 1;
		game->bullets--;
	}
}

int	ft_handle_mouse(int button, int x, int y, t_game *game)
{
	static int	weapon = 0;
	
	x++;
	y++;
	mlx_destroy_image(game->mlx.mlx, game->gun[0].img);
	mlx_destroy_image(game->mlx.mlx, game->gun[1].img);

	if (button == 3)
	{
		if (weapon++ == 0)
		{
			game->gun[0].img = mlx_xpm_file_to_image(game->mlx.mlx,
			"./img/knife.xpm", &game->gun[0].width, &game->gun[0].height);
			game->gun[1].img = mlx_xpm_file_to_image(game->mlx.mlx,
			"./img/knife_2.xpm", &game->gun[1].width, &game->gun[1].height);
		}
		else
		{
			game->gun[0].img = mlx_xpm_file_to_image(game->mlx.mlx,
			"./img/gun.xpm", &game->gun[0].width, &game->gun[0].height);
			game->gun[1].img = mlx_xpm_file_to_image(game->mlx.mlx,
			"./img/gun_2.xpm", &game->gun[1].width, &game->gun[1].height);
			weapon = 0;
		}
		printf("OH");
	}
	game->gun[0].addr = mlx_get_data_addr(game->gun[0].img,
	&game->gun[0].byte_p, &game->gun[0].line_l, &game->gun[0].end);
	game->gun[1].addr = mlx_get_data_addr(game->gun[1].img,
	&game->gun[1].byte_p, &game->gun[1].line_l, &game->gun[1].end);
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
			WINDOWS_X, WINDOWS_Y, "Cub3d");
	open_img(game);
	mlx_loop_hook(game->mlx.mlx, &render_next_frame, game);
	mlx_hook(game->mlx.windows, 2, 1L << 0, input, game);
	mlx_hook(game->mlx.windows, 3, 1L << 1, exput, game);
	mlx_hook(game->mlx.windows, 33, 1l << 5, free_and_destroy, game);
	mlx_mouse_hook(game->mlx.windows, &ft_handle_mouse, game);
	mlx_loop(game->mlx.mlx);
}

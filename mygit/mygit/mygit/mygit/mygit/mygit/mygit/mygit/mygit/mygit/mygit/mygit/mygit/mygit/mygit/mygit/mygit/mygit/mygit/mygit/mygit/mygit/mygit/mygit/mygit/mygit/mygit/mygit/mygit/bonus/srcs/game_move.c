/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:02:15 by flee              #+#    #+#             */
/*   Updated: 2022/06/07 21:20:14 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	move_up(t_game *game)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = game->player.pos_x;
	tmp_y = game->player.pos_y;
	game->player.pos_x += game->player.dir_x * 0.04;
	game->player.pos_y += game->player.dir_y * 0.04;
	if (!check_move(game))
	{
		game->player.pos_x = tmp_x;
		game->player.pos_y = tmp_y;
	}
}

void	move_right(t_game *game)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = game->player.pos_x;
	tmp_y = game->player.pos_y;
	game->player.pos_x += game->player.dir_y * 0.02;
	game->player.pos_y -= game->player.dir_x * 0.02;
	if (!check_move(game))
	{
		game->player.pos_x = tmp_x;
		game->player.pos_y = tmp_y;
	}
}

void	move_left(t_game *game)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = game->player.pos_x;
	tmp_y = game->player.pos_y;
	game->player.pos_x -= game->player.dir_y * 0.02;
	game->player.pos_y += game->player.dir_x * 0.02;
	if (!check_move(game))
	{
		game->player.pos_x = tmp_x;
		game->player.pos_y = tmp_y;
	}
}

void	move_down(t_game *game)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = game->player.pos_x;
	tmp_y = game->player.pos_y;
	game->player.pos_x -= game->player.dir_x * 0.04;
	game->player.pos_y -= game->player.dir_y * 0.04;
	if (!check_move(game))
	{
		game->player.pos_x = tmp_x;
		game->player.pos_y = tmp_y;
	}
}

void	rotate_right(t_game *game)
{
	float	rot_speed;
	double	olddir_x;
	double	oldplane_x;

	rot_speed = 0.02;
	olddir_x = game->player.dir_x;
	oldplane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(-rot_speed)
		- game->player.dir_y * sin(-rot_speed);
	game->player.dir_y = olddir_x * sin(-rot_speed)
		+ game->player.dir_y * cos(-rot_speed);
	game->player.plane_x = game->player.plane_x * cos(-rot_speed)
		- game->player.plane_y * sin(-rot_speed);
	game->player.plane_y = oldplane_x * sin(-rot_speed)
		+ game->player.plane_y * cos(-rot_speed);
}

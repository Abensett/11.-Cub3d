/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/1/16 14:02:15 by flee              #+#    #+#             */
/*   Updated: 2022/1/20 08:07:58 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	move_up(t_game *game)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = game->player.pos_x + game->player.dir_x * game->speed;
	tmp_y = game->player.pos_y + game->player.dir_y * game->speed;
	if (check_move(game, tmp_x, tmp_y))
	{
		game->player.pos_x += game->player.dir_x * game->speed;
		game->player.pos_y += game->player.dir_y * game->speed;
	}
	else
	{
		game->life -= 10 * game->speed;
		game->player.pos_x -= game->player.dir_x * game->speed * 5;
		game->player.pos_y -= game->player.dir_y * game->speed * 5;
	}
}

void	move_right(t_game *game)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = game->player.pos_x + game->player.dir_y * game->speed;
	tmp_y = game->player.pos_y - game->player.dir_x * game->speed;
	if (check_move(game, tmp_x, tmp_y))
	{
		game->player.pos_x += game->player.dir_y * game->speed;
		game->player.pos_y -= game->player.dir_x * game->speed;
	}
	else
	{
		game->life -= 10 * game->speed;
		game->player.pos_x -= game->player.dir_y * game->speed * 5;
		game->player.pos_y += game->player.dir_x * game->speed * 5;
	}
}

void	move_left(t_game *game)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = game->player.pos_x - game->player.dir_y * game->speed;
	tmp_y = game->player.pos_y + game->player.dir_x * game->speed;
	if (check_move(game, tmp_x, tmp_y))
	{
		game->player.pos_x -= game->player.dir_y * game->speed;
		game->player.pos_y += game->player.dir_x * game->speed;
	}
	else
	{
		game->life -= 10 * game->speed;
		game->player.pos_x += game->player.dir_y * game->speed * 5;
		game->player.pos_y -= game->player.dir_x * game->speed * 5;
	}
}

void	move_down(t_game *game)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = game->player.pos_x - game->player.dir_x * game->speed;
	tmp_y = game->player.pos_y - game->player.dir_y * game->speed;
	if (check_move(game, tmp_x, tmp_y))
	{
		game->player.pos_x -= game->player.dir_x * game->speed;
		game->player.pos_y -= game->player.dir_y * game->speed;
	}
	else
	{
		game->life -= 10 * game->speed;
		game->player.pos_x += game->player.dir_x * game->speed;
		game->player.pos_y += game->player.dir_y * game->speed;
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

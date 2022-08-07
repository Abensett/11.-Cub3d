/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 21:20:28 by abensett          #+#    #+#             */
/*   Updated: 2022/08/07 21:49:37 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	rotate_left(t_game *game)
{
	float	rot_speed;
	double	olddir_x;
	double	oldplane_x;

	rot_speed = 0.02;
	olddir_x = game->player.dir_x;
	oldplane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(rot_speed)
		- game->player.dir_y * sin(rot_speed);
	game->player.dir_y = olddir_x * sin(rot_speed)
		+ game->player.dir_y * cos(rot_speed);
	game->player.plane_x = game->player.plane_x * cos(rot_speed)
		- game->player.plane_y * sin(rot_speed);
	game->player.plane_y = oldplane_x * sin(rot_speed)
		+ game->player.plane_y * cos(rot_speed);
}

int	input(int key, t_game *game)
{
	if (key == 65307)
		free_and_destroy(game);
	else if (key == 97)
		move_left(game);
	else if (key == 119)
		move_up(game);
	else if (key == 115)
		move_down(game);
	else if (key == 100)
		move_right(game);
	else if (key == 65361)
		rotate_left(game);
	else if (key == 65363)
		rotate_right(game);
	else if (key ==32)
		ft_handle_shoot(game);
	printf("Keypress: %d\n", key);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:45:49 by flee              #+#    #+#             */
/*   Updated: 2022/08/06 17:40:11 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

/* default values when directed WEST or EAST */
void	player_dir2(t_game *game, char dir)
{
	if (dir == 'W')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
	if (dir == 'E')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
}

/* default values when directed NORTH or SOUTH */
void	player_dir(t_game *game, char dir)
{
	if (dir == 'N')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	if (dir == 'S')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
	game->life = 100;
	player_dir2(game, dir);
}

/* check if the character is there */
bool	check_character(t_game *game, int x, int y, char c)
{
	static int	count;

	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		count++;
		if (count > 1)
		{
			game->player.pos_x = -1;
			return (0);
		}
		game->player.pos_x = x + 0.5;
		game->player.pos_y = y + 0.5;
		player_dir(game, game->map.map[x][y]);
	}
	return (1);
}

/* return 0 if the element is not acceptable else return 1 */
bool	check_element(char c)
{
	if (c != ' ' && c != '0' && c != '1' && c != 'N'
		&& c != 'S' && c != 'E' && c != 'W')
		return (0);
	return (1);
}

/* store the direction of the player
 and check if the map is valid return 0 if not else return 1:
				-> elements are ' ' 0 1 N S E W
				-> store the direction of the character */
bool	parse_element(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map.map[x])
	{
		y = 0;
		while (game->map.map[x][y])
		{
			if (!check_element(game->map.map[x][y]))
				return (0);
			if (!check_character(game, x, y, game->map.map[x][y]))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

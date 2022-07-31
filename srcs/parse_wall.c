/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:41:24 by flee              #+#    #+#             */
/*   Updated: 2022/07/26 18:22:16 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

//  ??
bool	wall(char **map, int x, int y)
{
	if (map[x + 1][y] == ' ' || map[x - 1][y] == ' ' ||
			map[x][y + 1] == ' ' || map[x][y - 1] == ' ')
		return (0);
	return (1);
}

// check the inside of the map are 0
bool	check_in(t_game *game)
{
	unsigned long	x;
	unsigned long	y;

	x = (ft_size(game->map.map) - 1);
	while (x > 0)
	{
		y = 0;
		while (y < (ft_strlen(game->map.map[x]) - 1))
		{
			if (game->map.map[x][y] == '0')
			{
				if (!wall(game->map.map, x, y))
					return (0);
			}
			y++;
		}
		x--;
	}
	return (1);
}

// check if side is there
bool	check_side2(t_game *game, int x)
{
	int	y;

	y = 0;
	while (game->map.map[x][y])
	{
		if (game->map.map[x][y] != ' ' && game->map.map[x][y] != '1')
			return (0);
		y++;
	}
	return (1);
}

// check that the side are walls  
bool	check_side(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.map[x][y])
	{
		if (game->map.map[x][y] != ' ' && game->map.map[x][y] != '1')
			return (0);
		y++;
	}
	y -= 2;
	while (game->map.map[x])
	{
		if ((game->map.map[x][0] != ' ' && game->map.map[x][0] != '1')
				|| (game->map.map[x][y] != ' ' && game->map.map[x][y] != '1'))
			return (0);
		x++;
	}
	if (!check_side2(game, --x))
		return (0);
	return (1);
}

/* check if the walls, position of the player are valid */
void	parse_wall(t_game *game)
{
	if (!parse_element(game))
	{
		free_parse(game);
		return (printf("Problem in element\n"), exit (0));
	}
	if (!check_side(game))
	{
		free_parse(game);
		return (printf("Problem in wall\n"), exit (0));
	}
	if (!check_in(game))
	{
		free_parse(game);
		return (printf("Problem in wall\n"), exit (0));
	}
	if (game->player.pos_x == -1)
	{
		free_parse(game);
		return (printf("Problem in player\n"), exit (0));
	}
	if (!check_void(game))
	{
		free_parse(game);
		return (printf("Problem in empty space\n"), exit (0));
	}
}

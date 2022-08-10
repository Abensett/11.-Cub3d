/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:07:55 by flee              #+#    #+#             */
/*   Updated: 2022/08/10 02:17:54 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

bool	check_void(t_game *game)
{
	int	x;
	int	y;

	x = game->player.pos_x;
	y = game->player.pos_y;
	if (game->map.map[x + 1][y] == ' ' || game->map.map[x - 1][y] == ' ')
		return (0);
	if (game->map.map[x][y + 1] == ' ' || game->map.map[x][y - 1] == ' ')
		return (0);
	return (1);
}

// infos about Minimap, life, bullets
void	infos(t_game *game)
{
	char*	bullets;

	bullets = ft_itoa(game->bullets);
	mlx_string_put(game->mlx.mlx, game->mlx.windows, 50, 50, 0xFF0000,
	 "Minimap");
	if (game->life <= 40)
		mlx_string_put(game->mlx.mlx, game->mlx.windows,  WINDOWS_X - 375, 70,
		 0xFF00000, "You're about to die !");
	if(game->bullets <= 0)
			mlx_string_put(game->mlx.mlx, game->mlx.windows,  WINDOWS_X - 800, 70,
		 0xFFFFFF, "No more bullets !");
	else
		mlx_string_put(game->mlx.mlx, game->mlx.windows,  WINDOWS_X - 800, 70,
		 0xFFFFFF, bullets);
	free(bullets);
}
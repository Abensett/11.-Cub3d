/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:07:55 by flee              #+#    #+#             */
/*   Updated: 2022/06/07 21:34:33 by abensett         ###   ########.fr       */
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

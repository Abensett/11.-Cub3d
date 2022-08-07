/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameoverorwon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 00:05:30 by abensett          #+#    #+#             */
/*   Updated: 2022/08/08 00:40:41 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	write_on_screen(t_game *game, char *text, int pos[2], int color)
{
	int		x;
	int		y;

	x = pos[0] - ft_strlen(text) * 5;
	y = pos[1];
	mlx_string_put(game->mlx.mlx, game->mlx.windows, x, y, color, text);
	mlx_string_put(game->mlx.mlx, game->mlx.windows, 0, 0, color, text);

}

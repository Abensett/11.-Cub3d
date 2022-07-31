/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 21:32:32 by abensett          #+#    #+#             */
/*   Updated: 2022/06/07 21:33:50 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

bool	check_move(t_game *game)
{
	if (game->map.map[(int)game->player.pos_x][(int)game->player.pos_y] == '1')
		return (0);
	return (1);
}

char	*whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 9 && str[i] <= 13)
			str[i] = 32;
		i++;
	}
	return (str);
}

bool	str_is_digit(char **str)
{
	int	i;
	int	a;

	i = 0;
	while (str[i])
	{
		a = 0;
		while (str[i][a])
		{
			if (!ft_isdigit(str[i][a]))
				return (0);
			a++;
		}
		i++;
	}
	return (1);
}

bool	line_is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

bool	check_info(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (game->texture.floor[i] < 0 || game->texture.floor[i] > 255)
			return (0);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (game->texture.sky[i] < 0 || game->texture.sky[i] > 255)
			return (0);
		i++;
	}
	return (1);
}

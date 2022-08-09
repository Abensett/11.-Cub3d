/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:42:07 by flee              #+#    #+#             */
/*   Updated: 2022/08/09 03:01:31 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

/* store the RGB values */
void	set_background(int bck, t_game *game, char **rgb)
{
	if (ft_size(rgb) == 3 && str_is_digit(rgb))
	{
		if (bck == 0)
		{
			game->texture.floor[0] = ft_atoi(rgb[0]);
			game->texture.floor[1] = ft_atoi(rgb[1]);
			game->texture.floor[2] = ft_atoi(rgb[2]);
		}
		if (bck == 1)
		{
			game->texture.sky[0] = ft_atoi(rgb[0]);
			game->texture.sky[1] = ft_atoi(rgb[1]);
			game->texture.sky[2] = ft_atoi(rgb[2]);
		}
	}
}

/* store floor and ceilling RGB in structure, if not found  return 0 */
int	search_bck(t_game *game, char *str)
{
	char	**line;
	char	**rgb;

	str = whitespace(str);
	line = ft_split(str, ' ');
	if (ft_size(line) != 2)
		return (ft_free_tab(line), (0));
	rgb = ft_split(line[1], ',');
	if (ft_size(rgb) != 3)
		return (ft_free_tab(line), ft_free_tab(rgb), (0));
	else if (ft_strncmp(line[0], "F", ft_strlen(line[0])) == 0)
		set_background(0, game, rgb);
	else if (ft_strncmp(line[0], "C", ft_strlen(line[0])) == 0)
		set_background(1, game, rgb);
	else
		return (ft_free_tab(line), ft_free_tab(rgb), (0));
	return (ft_free_tab(line), ft_free_tab(rgb), (1));
}

/* store texture in structure, if not found returns 0 */
int	search_id(t_game *game, char *str)
{
	char	**line;

	str = whitespace(str);
	line = ft_split(str, ' ');
	if ((ft_size(line)) != 2)
		return ((ft_free_tab(line)), (0));
	if (ft_strncmp(line[0], "N", ft_strlen(line[0])) == 0
		|| ft_strncmp(line[0], "NO", ft_strlen(line[0])) == 0)
		game->texture.north = ft_strdup(line[1]);
	else if (ft_strncmp(line[0], "S", ft_strlen(line[0])) == 0
		|| ft_strncmp(line[0], "SO", ft_strlen(line[0])) == 0)
		game->texture.south = ft_strdup(line[1]);
	else if (ft_strncmp(line[0], "W", ft_strlen(line[0])) == 0
		|| ft_strncmp(line[0], "WE", ft_strlen(line[0])) == 0)
		game->texture.west = ft_strdup(line[1]);
	else if (ft_strncmp(line[0], "E", ft_strlen(line[0])) == 0
		|| ft_strncmp(line[0], "EA", ft_strlen(line[0])) == 0)
		game->texture.east = ft_strdup(line[1]);
	else
		return ((ft_free_tab(line)), (0));
	return ((ft_free_tab(line)), (1));
}

// extract texture and RGB and check map
bool	parse_texture(t_game *game)
{
	int	i;
	int	ctrl;

	i = 0;
	ctrl = 1;
	while (game->map.map[i] && ctrl < 7)
	{
		if (search_id(game, game->map.map[i]))
			ctrl++;
		if (search_bck(game, game->map.map[i]))
			ctrl++;
		i++;
	}
	if (ctrl != 7 || i == ft_size(game->map.map))
		return (0);
	while (line_is_empty(game->map.map[i]) && (i + 1) < ft_size(game->map.map))
		i++;
	if ((ft_size(game->map.map) != i))
	{
		game->map.map = ft_popTab(game->map.map, i);
		return (1);
	}
	return (0);
}

/* initianalize textures, extract and check textures and RGB for floor
	and ceiling
	check_info -> check RGB values*/
void	parse_map(t_game *game)
{
	game->texture.floor[0] = -1;
	game->texture.floor[1] = -1;
	game->texture.floor[2] = -1;
	game->texture.sky[0] = -1;
	game->texture.sky[1] = -1;
	game->texture.sky[2] = -1;
	game->player.pos_x = -1;
	game->player.pos_y = -1;
	game->texture.east = NULL;
	game->texture.south = NULL;
	game->texture.north = NULL;
	game->texture.west = NULL;
	game->texture.skys = NULL;
	game->texture.floors = NULL;
	if (!parse_texture(game) || !check_info(game))
	{
		free_parse(game);
		return (printf("Problem in description\n"), exit (0));
	}
	game->texture.skys = ft_strdup("./img/sky.xpm");
	game->texture.floors = ft_strdup("./img/floor.xpm");
	game->depth = ft_calloc(WINDOWS_X, sizeof(double));
	if (game->depth == 0)
		exit(1);
}

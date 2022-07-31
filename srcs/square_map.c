/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:42:48 by flee              #+#    #+#             */
/*   Updated: 2022/07/25 22:11:30 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

// copy src into dst
char	*cpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == '\n')
			return (dest);
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

// return longest line in file 
int	longest_str(char **map)
{
	int	i;
	int	size;
	int	longest;

	i = 0;
	size = 0;
	longest = ft_strlen(map[i]);
	while (map[i])
	{
		size = ft_strlen(map[i]);
		if (size > longest)
			longest = size;
		i++;
	}
	return (longest);
}

// square map of the given file by fiding the longest line
void	square_map(t_game *game)
{
	int		longest;
	int		i;
	char	*str;

	longest = longest_str(game->map.map);
	i = 0;
	while (game->map.map[i])
	{
		str = malloc(sizeof(char) * (longest + 1));
		if (!str)
			return ;
		ft_memset(str, ' ', longest);
		str = cpy(str, game->map.map[i]);
		free(game->map.map[i]);
		game->map.map[i] = str;
		i++;
	}
}

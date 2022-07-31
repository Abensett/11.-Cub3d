/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 13:08:08 by flee              #+#    #+#             */
/*   Updated: 2022/06/07 21:36:41 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

bool	is_cub(char *file)
{
	char	*tmp;
	int		len;

	len = ft_strlen(file);
	if (len < 4)
		return (0);
	tmp = ft_substr(file, (len - 4), 4);
	if (ft_strncmp(tmp, ".cub", 4) != 0)
	{
		printf("Problem in extension !\n");
		return (free(tmp), (0));
	}
	return (free(tmp), (1));
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (0);
	if (!is_cub(argv[1]))
		return (0);
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	get_file(argv[1], game);
	parse_map(game);
	square_map(game);
	parse_wall(game);
	game_loop(game);
	return (0);
}

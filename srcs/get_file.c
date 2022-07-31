/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:04:17 by flee              #+#    #+#             */
/*   Updated: 2022/06/19 19:48:56 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	free_exit(t_game *game)
{
	free(game);
	printf("Problem in file\n");
	exit(0);
}

// count the lines of the files
int	count_line(char *file, t_game *game)
{
	int		fd;
	int		read_ret;
	char	c;
	int		x;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		free_exit(game);
	x = 1;
	while (1)
	{
		read_ret = read(fd, &c, 1);
		if (read_ret == 0)
			break ;
		if (read_ret < 0)
			return (-1);
		if (c == '\n')
			x++;
	}
	close(fd);
	return (x);
}

// open the file and stock it game->map.map which is an array of str
void	get_file(char *map, t_game *game)
{
	int		fd;
	char	*line;
	char	**map_ret;
	int		i;

	i = count_line(map, game);
	if (i == -1)
		free_exit(game);
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	map_ret = malloc(sizeof(char *) * (i + 1));
	if (!map_ret)
		return ;
	i = 0;
	while (line)
	{
		map_ret[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map_ret[i] = 0;
	game->map.map = map_ret;
}

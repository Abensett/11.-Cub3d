/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:36:38 by abensett          #+#    #+#             */
/*   Updated: 2022/08/10 04:20:06 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

static void	sprite_init_pos(t_game *game, int index, int i, int j)
{
	game->sprites[index].pos[0] = i;
	game->sprites[index].pos[1] = j;
}


int		sprites_init(t_game *game)
{
	int		i;
	int		j;
	int		index;

	if (!(game->sprites = ft_calloc(game->nb_sprites, sizeof(t_sprite))))
		return (0);
	index = 0;
	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == '2')
				sprite_init_pos(game, index++, i, j);
			j++;
		}
		i++;
	}
	return (1);
}

void	compute_distances(t_game *game)
{
	int	i;

	game->won = 1;
	i = 0;
	while (i < game->nb_sprites)
	{
		game->sprites[i].distance =
			pow(game->player.pos_x - game->sprites[i].pos[0], 2)
			+ pow(game->player.pos_y - game->sprites[i].pos[1], 2);
		if (!game->sprites[i].dead)
			game->won = 0;
		i++;
	}
}

void	sort_sprites(t_game *game)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < game->nb_sprites)
	{
		j = 0;
		while (j < game->nb_sprites - i - 1)
		{
			if (game->sprites[i].distance < game->sprites[i + 1].distance)
			{
				tmp = game->sprites[i];
				game->sprites[i] = game->sprites[i + 1];
				game->sprites[i + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	draw_line_sprite(t_game *game, t_spritedata data, int i,
	int bbox_x[2])
{
	int		bbox_y[2];
	int		j;
	int		color;

	bbox_y[0] = WINDOWS_Y / 2
		- data.sprite_size / 2;
	bbox_y[1] = WINDOWS_Y / 2
		+ data.sprite_size / 2;
	j = (bbox_y[0] < 0) ? 0 : bbox_y[0];
	while (j < (bbox_y[1] >= WINDOWS_Y
		? WINDOWS_Y - 1 : bbox_y[1]))
	{
		color = my_tex_color(game->sprite,
			((i - bbox_x[0]) * 1.0) / (bbox_x[1] - bbox_x[0]),
			((j - bbox_y[0]) * 1.0) / (bbox_y[1] - bbox_y[0]),
			((bbox_x[1] - bbox_x[0]) * 3.0 / (WINDOWS_Y)));
		if (color != 0)
			my_mlx_pixel_put(&game->windows, i, j, color);
		j++;
	}
}

void	draw_sprite(t_game *game, t_spritedata data)
{
	int		bbox_x[2];
	int		i;

	bbox_x[0] = data.sprite_x - data.sprite_size / 2;
	bbox_x[1] = data.sprite_x + data.sprite_size / 2;
	game->sprites[data.index].alive = bbox_x[0] < WINDOWS_X /
		2 && bbox_x[1] > WINDOWS_X / 2
		&& data.transform[1] < 2;
	i = (bbox_x[0] < 0) ? 0 : bbox_x[0];
	// while (i <= (bbox_x[1] >= WINDOWS_X ?
	// 	WINDOWS_X - 1 : bbox_x[1]))
	// {
	// 	if (data.transform[1] > 0 && data.transform[1] < game->depth[i])
	// 		draw_line_sprite(game, data, i, bbox_x);
	// 	i++;
	// }
}
void	draw_sprites(t_game *game)
{
	t_spritedata	data;
	double			sprite_pos[2];
	double			det;

	compute_distances(game);
	sort_sprites(game);
	load_texture(game, &game->sprite, "./img/sheep.xpm");
	data.index = 0;
	while (data.index < game->nb_sprites)
	{
		sprite_pos[0] = game->sprites[data.index].pos[0] + 0.5 - game->player.pos_x;
		sprite_pos[1] = game->sprites[data.index].pos[1] + 0.5 - game->player.pos_y;
		det = 1.0 / (game->player.plane_x * game->player.dir_y
			- game->player.dir_x * game->player.plane_y);
		data.transform[0] = det * (game->player.dir_y * sprite_pos[0]
			- game->player.dir_x * sprite_pos[1]);
		data.transform[1] = det * (-game->player.plane_y * sprite_pos[0]
			+ game->player.plane_x * sprite_pos[1 ]);
		data.sprite_x = (int)((WINDOWS_X / 2) *
			(1 + data.transform[0] / data.transform[1]));
		data.sprite_size = abs((int)(WINDOWS_Y / data.transform[1]));
		if (!game->sprites[data.index].dead)
			draw_sprite(game, data);
		data.index++;
	}
}

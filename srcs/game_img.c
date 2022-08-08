/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:17:01 by flee              #+#    #+#             */
/*   Updated: 2022/08/08 11:35:58 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	img_addr(t_game *game)
{
	game->north.addr = mlx_get_data_addr(game->north.img,
			&game->north.byte_p, &game->north.line_l, &game->north.end);
	game->east.addr = mlx_get_data_addr(game->east.img,
			&game->east.byte_p, &game->east.line_l, &game->east.end);
	game->south.addr = mlx_get_data_addr(game->south.img,
			&game->south.byte_p, &game->south.line_l, &game->south.end);
	game->west.addr = mlx_get_data_addr(game->west.img,
			&game->west.byte_p, &game->west.line_l, &game->west.end);
	game->floor.addr = mlx_get_data_addr(game->floor.img,
			&game->floor.byte_p, &game->floor.line_l, &game->floor.end);
	game->sky.addr = mlx_get_data_addr(game->sky.img,
			&game->sky.byte_p, &game->sky.line_l, &game->sky.end);
	game->lifebar.addr = mlx_get_data_addr(game->lifebar.img,
			&game->lifebar.byte_p, &game->lifebar.line_l, &game->lifebar.end);
	game->gun[0].addr = mlx_get_data_addr(game->gun[0].img,
			&game->gun[0].byte_p, &game->gun[0].line_l, &game->gun[0].end);
	game->gun[1].addr = mlx_get_data_addr(game->gun[1].img,
			&game->gun[1].byte_p, &game->gun[1].line_l, &game->gun[1].end);
	game->windows.addr = mlx_get_data_addr(game->windows.img,
			&game->windows.byte_p, &game->windows.line_l, &game->windows.end);
}

void	check_img(t_game *game)
{
	load_texture(game, &game->gun[2], "./img/knife.xpm");
	load_texture(game, &game->gun[3], "./img/knife_2.xpm");
	if (!game->north.img || !game->east.img)
		clean_img(game);
	if (!game->south.img || !game->west.img || !game->windows.img)
		clean_img(game);
}

void	open_img(t_game *game)
{
	game->north.img = mlx_xpm_file_to_image(game->mlx.mlx,
			game->texture.north, &game->north.byte_p, &game->north.line_l);
	game->east.img = mlx_xpm_file_to_image(game->mlx.mlx,
			game->texture.east, &game->east.byte_p, &game->east.line_l);
	game->south.img = mlx_xpm_file_to_image(game->mlx.mlx,
			game->texture.south, &game->south.byte_p, &game->south.line_l);
	game->west.img = mlx_xpm_file_to_image(game->mlx.mlx,
			game->texture.west, &game->west.byte_p, &game->west.line_l);
	game->sky.img = mlx_xpm_file_to_image(game->mlx.mlx,
			game->texture.skys, &game->sky.byte_p, &game->sky.line_l);
	game->floor.img = mlx_xpm_file_to_image(game->mlx.mlx,
			game->texture.floors, &game->floor.byte_p, &game->floor.line_l);
	game->gun[0].img = mlx_xpm_file_to_image(game->mlx.mlx,
			"./img/gun.xpm", &game->gun[0].width, &game->gun[0].height);
	game->gun[1].img = mlx_xpm_file_to_image(game->mlx.mlx,
			"./img/gun_2.xpm", &game->gun[1].width, &game->gun[1].height);
	game->lifebar.img = mlx_xpm_file_to_image(game->mlx.mlx,
			"./img/lifebar.xpm", &game->lifebar.width, &game->lifebar.height);
	game->windows.img = mlx_new_image(game->mlx.mlx, WINDOWS_X, WINDOWS_Y);
	check_img(game);
	img_addr(game);
	game->texture.f_rgb = create_rgb(game->texture.floor[0],
			game->texture.floor[1], game->texture.floor[2]);
	game->texture.s_rgb = create_rgb(game->texture.sky[0], game->texture.sky[1],
			game->texture.sky[2]);
}

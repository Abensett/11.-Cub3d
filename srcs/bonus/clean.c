/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:49:08 by flee              #+#    #+#             */
/*   Updated: 2022/08/10 11:35:48 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D_bonus.h"

// free map and texture then game
void	free_parse(t_game *game)
{
	ft_putendl_fd("Error", 2);
	if (game->texture.east != NULL)
		free(game->texture.east);
	if (game->texture.north != NULL)
		free(game->texture.north);
	if (game->texture.south != NULL)
		free(game->texture.south);
	if (game->texture.west != NULL)
		free(game->texture.west);
	if (game->texture.skys != NULL)
		free(game->texture.skys);
	if (game->texture.floors != NULL)
		free(game->texture.floors);
	ft_free_tab(game->map.map);
	free(game);
	system("killall -9 vlc");
}

// destroy images im case of error
void	clean_img(t_game *game)
{
	ft_putendl_fd("Error", 2);
	printf("Problem in texture path !\n");
	if (game->north.img)
		mlx_destroy_image(game->mlx.mlx, game->south.img);
	if (game->south.img)
		mlx_destroy_image(game->mlx.mlx, game->south.img);
	if (game->west.img)
		mlx_destroy_image(game->mlx.mlx, game->west.img);
	if (game->east.img)
		mlx_destroy_image(game->mlx.mlx, game->east.img);
	if (game->windows.img)
		mlx_destroy_image(game->mlx.mlx, game->windows.img);
	mlx_destroy_window(game->mlx.mlx, game->mlx.windows);
	mlx_destroy_display(game->mlx.mlx);
	free(game->mlx.mlx);
	free_parse(game);
	system("killall -9 vlc");
	exit (EXIT_SUCCESS);
}

void	free_and_destroy2(t_game *game)
{
	free(game->depth);
	free(game->texture.east);
	free(game->texture.north);
	free(game->texture.south);
	free(game->texture.west);
	ft_free_tab(game->map.map);
	free(game->mlx.mlx);
	free(game);
	system("killall -9 vlc");
}

// destroy images and windows, free map and texture then game and exit
int	free_and_destroy(t_game *game)
{
	int	i;

	i = 0;
	mlx_destroy_image(game->mlx.mlx, game->north.img);
	mlx_destroy_image(game->mlx.mlx, game->south.img);
	mlx_destroy_image(game->mlx.mlx, game->west.img);
	mlx_destroy_image(game->mlx.mlx, game->east.img);
	mlx_destroy_image(game->mlx.mlx, game->sky.img);
	mlx_destroy_image(game->mlx.mlx, game->floor.img);
	mlx_destroy_image(game->mlx.mlx, game->windows.img);
	mlx_destroy_window(game->mlx.mlx, game->mlx.windows);
	while (i < 4)
		mlx_destroy_image(game->mlx.mlx, game->gun[i++].img);
	mlx_destroy_image(game->mlx.mlx, game->game_over.img);
	mlx_destroy_image(game->mlx.mlx, game->sprite.img);
	mlx_destroy_display(game->mlx.mlx);
	free(game->sprites);
	free(game->texture.skys);
	free(game->texture.floors);
	free_and_destroy2(game);
	exit (EXIT_SUCCESS);
}

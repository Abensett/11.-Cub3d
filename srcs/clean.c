/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:49:08 by flee              #+#    #+#             */
/*   Updated: 2022/08/01 03:25:28 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

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
		free(game->texture.west);
	if (game->texture.floors != NULL)
		free(game->texture.west);
	ft_free_tab(game->map.map);
	free(game);
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
	if (game->sky.img)
		mlx_destroy_image(game->mlx.mlx, game->sky.img);
	if (game->floor.img)
		mlx_destroy_image(game->mlx.mlx, game->floor.img);
	mlx_destroy_window(game->mlx.mlx, game->mlx.windows);
	mlx_destroy_display(game->mlx.mlx);
	free(game->mlx.mlx);
	free_parse(game);
	exit (EXIT_SUCCESS);
}

// destroy images and windows, free map and texture then game and exit
int	free_and_destroy(t_game *game)
{
	mlx_destroy_image(game->mlx.mlx, game->north.img);
	mlx_destroy_image(game->mlx.mlx, game->south.img);
	mlx_destroy_image(game->mlx.mlx, game->west.img);
	mlx_destroy_image(game->mlx.mlx, game->east.img);
	mlx_destroy_image(game->mlx.mlx, game->sky.img);
	mlx_destroy_image(game->mlx.mlx, game->floor.img);
	mlx_destroy_image(game->mlx.mlx, game->windows.img);
	mlx_destroy_window(game->mlx.mlx, game->mlx.windows);
	mlx_destroy_display(game->mlx.mlx);
	free(game->texture.east);
	free(game->texture.north);
	free(game->texture.south);
	free(game->texture.west);
	ft_free_tab(game->map.map);
	free(game->mlx.mlx);
	free(game);
	exit (EXIT_SUCCESS);
}

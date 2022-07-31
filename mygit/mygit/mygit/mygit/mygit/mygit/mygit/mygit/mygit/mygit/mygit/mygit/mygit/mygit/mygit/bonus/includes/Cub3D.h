/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:06:09 by flee              #+#    #+#             */
/*   Updated: 2022/06/19 18:34:39 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define WINDOWS_X 	1500
# define WINDOWS_Y 	1000
# define TEX_SIZE	64

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	step;
	int		step_x;
	int		step_y;
	int		hit;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	int		side;
}	t_ray;

typedef struct s_map
{
	char	**map;
	int		grid_size;
}	t_map;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor[3];
	int		f_rgb;
	int		sky[3];
	int		s_rgb;
}	t_texture;

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	double	dir_x;
	double	dir_y;
	double	pa;
	float	plane_x;
	float	plane_y;
	int		map_x;
	int		map_y;
}	t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*windows;
	size_t	w_x;
	size_t	w_y;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		byte_p;
	int		line_l;
	int		end;
}	t_img;

typedef struct s_game
{
	t_mlx		mlx;
	t_map		map;
	t_texture	texture;
	t_player	player;
	t_img		windows;
	t_img		north;
	t_img		south;
	t_img		west;
	t_img		east;
	t_ray		ray;
}	t_game;

void			get_file(char *map, t_game *game);
void			parse_map(t_game *game);
void			square_map(t_game *game);
void			game_loop(t_game *game);
void			open_img(t_game *game);
void			raycasting(t_game *game);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
unsigned int	img_pix_get(t_img *img, int x, int y);
int				create_rgb(int r, int g, int b);
int				input(int key, t_game *game);
void			parse_wall(t_game *game);
bool			parse_element(t_game *game);
bool			check_move(t_game *game);
void			verline(t_game *game, int x, int sky);
void			ray_draw(t_game *game);
void			ray_hit(t_game *game);
void			ray_sideDist(t_game *game);
void			ray_init(t_game *game, int x);
int				free_and_destroy(t_game *game);
void			free_parse(t_game *game);
char			*whitespace(char *str);
bool			str_is_digit(char **str);
bool			line_is_empty(char *str);
bool			check_info(t_game *game);
bool			check_void(t_game *game);
void			clean_img(t_game *game);

//game_move.c game_move2.c
void			move_up(t_game *game);
void			move_right(t_game *game);
void			move_left(t_game *game);
void			move_down(t_game *game);
void			rotate_right(t_game *game);
void			rotate_left(t_game *game);
int				input(int key, t_game *game);

#endif

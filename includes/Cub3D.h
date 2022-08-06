/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:06:09 by flee              #+#    #+#             */
/*   Updated: 2022/08/06 22:05:14 by abensett         ###   ########.fr       */
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

/*********************************************************************
- camera_X  	= x-coord. on the camera plane -> left negative right positive
- ray_dir_x		=
- map_x, map_y  = the current square of the map the ray is in
- side_dist_x,y = the distance from its start posi to the first x-side,  y-side
- delta_dist_x,y= distance from 1 x-side to the next x-side, respectfully y-side
- perp_wall_dist= used to calculate the length of the ray (dist entre joueur mur)
- step 			=
- step_x, step_y= step in x or y-direction (either +1 or -1)
- hit			= 1 if wall touch else 0
- side			= 0 si un cote x touche 1 si cote y
- lineheight	= height of line to draw
- drawstart		= position of the beginning of the drawing
- drawend		= self-explanatory
- wall x		= for all the rays
 *********************************************************************/
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
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	float	ray_dir_x0;
	float	ray_dir_x1;
	float	ray_dir_y0;
	float	ray_dir_y1;
	int		position;
	float	pos_z;
	float	row_distance;
	float	floor_step_x;
	float	floor_step_y;
	float	floor_x;
	float	floor_y;
	int		cell_x;
	int		cell_y;
}	t_ray;

/*********************************************************************
-map 			= array of str usef to stock the .cub file
 *********************************************************************/
typedef struct s_map
{
	char	**map;
	int		grid_size;
}	t_map;

/*********************************************************************
- * north = north texture
- floor[3] = RGB of the color of the floor
- sky [3] =  RGB of the color of the ceiling
 *********************************************************************/
typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*skys;
	char	*floors;
	int		floor[3];
	int		f_rgb;
	int		sky[3];
	int		s_rgb;
}	t_texture;

/*********************************************************************
- pox_X,pos_Y  = player position
- dir_x, dir_y = direction vector
- pa 		   =
- plane_x, y   =  2nd raycaster version of camera plane
- map_x, map_y = the current square of the map the ray is in
 *********************************************************************/
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

/***********************************************************************
 - mlx structure
 ************************************************************************/
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
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	int	 		life;
	float		speed;
	int 		gun_shift;
	int 		gun_dir;
	t_mlx		mlx;
	t_map		map;
	t_texture	texture;
	t_player	player;
	t_img		windows;
	t_img		north;
	t_img		south;
	t_img		west;
	t_img		sky;
	t_img		floor;
	t_img		east;
	t_ray		ray;
	t_img		lifebar;
	t_img		gun;
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
bool			check_move(t_game *game, float tmp_x, float tmp_y);


void			draw_mini_map(t_game *game, int color);
void			draw_sky(t_game *game, int y);
int				apply_shadow(double dist, int color);
void			ft_life_bar(t_game *game);
void			ft_gun(t_game *game, int shooting);
void			write_text(t_game *game, int pos[2], char *text, int color);


#endif

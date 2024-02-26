/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:32:18 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/26 12:50:41 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <math.h>

# include "misc.h"
# include "parsing.h"
# include "MLX42.h"

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 768

# define EAST_ANGLE 0		// 0 degrees in radians		
# define NORTH_ANGLE PI_2	// 90 degrees in radians
# define WEST_ANGLE PI		// 180 degrees in radians
# define SOUTH_ANGLE PI3_2	// 270 degrees in radians

# define NORTH_TEXTURE 0
# define SOUTH_TEXTURE 1
# define EAST_TEXTURE 2
# define WEST_TEXTURE 3

# define FOV 1.0471975512 // 60 degrees in radians
# define TILE_SIZE 64
# define TEXTURE_SIZE 64
# define STEP_SIZE 1

# define MV_STEP 16

# define UP_KEY MLX_KEY_W		// W
# define DOWN_KEY MLX_KEY_S		// S
# define LEFT_KEY MLX_KEY_A		// A
# define RIGHT_KEY MLX_KEY_D	// D

# define ANGLE_STEP 0.1

# define LEFT_ARROW_KEY MLX_KEY_LEFT
# define RIGHT_ARROW_KEY MLX_KEY_RIGHT

# define ESC_KEY 53

typedef struct s_wall_info
{
	int	wall_start;
	int	wall_end;
	int	wall_height;
}	t_wall_info;

typedef struct s_ray_info
{
	int		x;
	bool	is_hit_horizontal;
	double	ray_x;
	double	ray_y;
	double	hit_ratio;
	double	dist;
	double	angle;
}	t_ray_info;

typedef struct s_player
{
	double	x;
	double	y;
	double	angle;
}	t_player;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	t_player	*player;
}	t_map;

typedef struct s_game
{
	mlx_t			*mlx;
	t_map			*map;
	mlx_texture_t	*textures[4];
	uint32_t		floor_color;
	uint32_t		ceiling_color;
	mlx_image_t		*last_frame;
}				t_game;

t_game			*ft_init_game(char *config_file);
void			ft_setup_hooks(t_game *game);
void			ft_free_game(t_game *game);

bool			ft_move_forward_backward(t_game *game, int key);
bool			ft_strafe(t_game *game, int key);
bool			ft_rotate(t_game *game, int key);
void			ft_render(t_game *game);

uint32_t		mlx_get_pixel_color(mlx_texture_t *texture, uint32_t x, uint32_t y);
void			*ft_get_texture(t_ray_info ray_info, t_game *game);
double			ft_get_tex_y(int y, t_wall_info wall_info);
double			ft_get_tex_x(double hit_ratio);
uint32_t		ft_get_texture_pixel(double x, double y,
					mlx_texture_t *texture);

void			ft_free_map(t_map	*map);
bool			ft_get_hit_point(double *x, double *y,
					double angle, t_map *map);
void			ft_put_wall_line(mlx_image_t *img, t_ray_info ray_info,
					t_wall_info wall_info, mlx_texture_t *texture);

#endif
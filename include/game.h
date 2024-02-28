/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:32:18 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/28 14:20:07 by migarci2         ###   ########.fr       */
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

# define SHADING_QUOFICIENT 0.0007f

# define PLAYER_WIDTH 16
# define PLAYER_HEIGHT 16

# define EAST_ANGLE 0		// 0 degrees in radians		
# define NORTH_ANGLE PI3_2	// 90 degrees in radians
# define WEST_ANGLE PI		// 180 degrees in radians
# define SOUTH_ANGLE PI_2	// 270 degrees in radians

# define NORTH_TEXTURE 0
# define SOUTH_TEXTURE 1
# define EAST_TEXTURE 2
# define WEST_TEXTURE 3

# define FOV 1.0471975512 // 60 degrees in radians
# define TILE_SIZE 64
# define TEXTURE_SIZE 64
# define STEP_SIZE 1

# define MV_STEP 128

# define UP_KEY MLX_KEY_W		// W
# define DOWN_KEY MLX_KEY_S		// S
# define LEFT_KEY MLX_KEY_A		// A
# define RIGHT_KEY MLX_KEY_D	// D

# define ANGLE_STEP 1.5

# define LEFT_ARROW_KEY MLX_KEY_LEFT
# define RIGHT_ARROW_KEY MLX_KEY_RIGHT

# define ESC_KEY 53

typedef struct s_dda
{
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
}	t_dda;


typedef struct s_ray_info
{
	int		x;
	bool	is_hit_horizontal;
	double	x_prev;
	double	y_prev;
	double	ray_x;
	double	ray_y;
	double	y_step;
	double	x_step;
	double	hit_ratio;
	double	dist;
	double	angle;
}	t_ray_info;

typedef struct s_wall_info
{
	int				wall_start;
	int				wall_end;
	int				wall_height;
	t_ray_info		ray_info;
	mlx_texture_t	*texture;
	double			texture_offset;
}	t_wall_info;

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

bool			ft_is_position_valid(t_game *game, double new_pos[2],
					double width, double height);
bool			ft_move_forward_backward(t_game *game, int key);
bool			ft_strafe(t_game *game, int key);
bool			ft_adjust_movement_for_wall(t_game *game,
					double *new_x, double *new_y, double angle);
bool			ft_adjust_strafe_for_wall(t_game *game,
					double *new_x, double *new_y);
bool			ft_rotate(t_game *game, int key);
void			ft_render(t_game *game);

uint32_t		mlx_get_pixel_color(mlx_texture_t *texture,
					uint32_t x, uint32_t y);
void			*ft_get_texture(t_ray_info ray_info, t_game *game);
uint32_t		ft_get_texture_pixel(double x, double y,
					mlx_texture_t *texture);
void			ft_put_line(mlx_image_t *img, int pos[2],
					int x, uint32_t color);

int	ft_get_hit_direction(t_ray_info *ray_info);

void			ft_free_map(t_map	*map);
void			ft_get_hit_point(t_ray_info *ray_info, t_map *map);
void			ft_put_wall_line(mlx_image_t *img, t_wall_info wall_info);
#endif
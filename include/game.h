/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:32:18 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/24 22:49:02 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <math.h>

# include "misc.h"
# include "MLX42.h"

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 768

# define NORTH_ANGLE M_PI_2
# define EAST_ANGLE 0
# define SOUTH_ANGLE 4.71238898038 // 270 degrees in radians
# define WEST_ANGLE M_PI

# define NORTH_TEXTURE 0
# define SOUTH_TEXTURE 1
# define EAST_TEXTURE 2
# define WEST_TEXTURE 3


# define MOVE_STEP 0.1

# define UP_KEY 87			// W
# define DOWN_KEY 83		// S
# define LEFT_KEY 65		// A
# define RIGHT_KEY 68		// D


# define ANGLE_STEP 0.05

# define LEFT_ARROW_KEY 263
# define RIGHT_ARROW_KEY 262

# define ESC_KEY 53

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
}				t_player;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	t_player	*player;
}				t_map;

typedef struct s_game
{
	void	*mlx;
	t_map	*map;
	void	*textures[4];
	int		floor_color[3];
	int		ceiling_color[3];
}				t_game;

t_game	*ft_init_game(char *config_file);
void	ft_setup_hooks(t_game *game);
void	ft_free_game(t_game *game);

int		ft_move_forward_backward(t_game *game, int key);
int		ft_strafe(t_game *game, int key);
int		ft_rotate(t_game *game, int key);

void	ft_render(t_game *game);

void	ft_free_map(t_map	*map);

#endif
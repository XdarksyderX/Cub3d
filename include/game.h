/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:32:18 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/24 18:26:18 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <math.h>

# include "misc.h"
# include "MLX42.h"

# define NORTH_ANGLE M_PI_2
# define EAST_ANGLE 0
# define SOUTH_ANGLE 4.71238898038 // 270 degrees in radians
# define WEST_ANGLE M_PI

# define NORTH_TEXTURE 0
# define SOUTH_TEXTURE 1
# define EAST_TEXTURE 2
# define WEST_TEXTURE 3

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

void	ft_free_map(t_map	*map);

#endif
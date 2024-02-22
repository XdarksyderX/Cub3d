/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:32:18 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/22 20:43:56 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "misc.h"
# include "MLX42.h"

typedef	struct s_player
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
	void	*win;
	t_map	*map;
	void	*textures[4];
	int		floor_color[3];
	int		ceiling_color[3];
}				t_game;

#endif
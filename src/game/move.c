/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:25:12 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/26 18:55:22 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static bool	ft_in_limits(int map_x, int map_y, t_game *game)
{
	if (map_x < 0 || map_x >= game->map->width
		|| map_y < 0 || map_y >= game->map->height)
		return (false);
	return (true);
}

bool	ft_is_position_valid(t_game *game, double new_x, double new_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(new_x / TILE_SIZE);
	map_y = (int)(new_y / TILE_SIZE);
	if (!ft_in_limits(map_x, map_y, game))
		return (false);
	if (game->map->map[map_y][map_x] == '1')
		return (false);
	return (true);
}

bool	ft_change_position(t_game *game, double new_x, double new_y)
{
	if (ft_is_position_valid(game, new_x, new_y))
	{
		game->map->player->x = new_x;
		game->map->player->y = new_y;
		return (true);
	}
	else
		return (false);
}

bool	ft_move_forward_backward(t_game *game, int key)
{
	double	new_x;
	double	new_y;
	double	angle;

	angle = game->map->player->angle;
	if (key == DOWN_KEY)
		angle += PI;
	new_x = game->map->player->x + cos(angle) * MV_STEP * game->mlx->delta_time;
	new_y = game->map->player->y + sin(angle) * MV_STEP * game->mlx->delta_time;
	if (!ft_is_position_valid(game, new_x, new_y))
	{
		if (!ft_adjust_movement_for_wall(game, &new_x, &new_y, angle))
			return (false);
	}
	return (ft_change_position(game, new_x, new_y));
}

bool	ft_strafe(t_game *game, int key)
{
	double	new_x;
	double	new_y;
	double	angle;

	angle = game->map->player->angle;
	if (key == RIGHT_KEY)
		angle += PI_2;
	else if (key == LEFT_KEY)
		angle -= PI_2;
	new_x = game->map->player->x + cos(angle) * MV_STEP * game->mlx->delta_time;
	new_y = game->map->player->y + sin(angle) * MV_STEP * game->mlx->delta_time;
	if (!ft_is_position_valid(game, new_x, new_y))
	{
		if (!ft_adjust_strafe_for_wall(game, &new_x, &new_y))
			return (false);
	}
	return (ft_change_position(game, new_x, new_y));
}

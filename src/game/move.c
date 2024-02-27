/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:25:12 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/27 18:36:14 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

bool	ft_change_position(t_game *game, double new_pos[2],
	int player_width, int player_height)
{
	if (ft_is_position_valid(game, new_pos, player_width, player_height))
	{
		game->map->player->x = new_pos[0];
		game->map->player->y = new_pos[1];
		return (true);
	}
	else
		return (false);
}

bool	ft_move_forward_backward(t_game *game, int key)
{
	double	new_pos[2];
	double	angle;

	angle = game->map->player->angle;
	if (key == DOWN_KEY)
		angle += PI;
	new_pos[0] = game->map->player->x
		+ cos(angle) * MV_STEP * game->mlx->delta_time;
	new_pos[1] = game->map->player->y
		+ sin(angle) * MV_STEP * game->mlx->delta_time;
	if (!ft_is_position_valid(game, new_pos, PLAYER_WIDTH, PLAYER_HEIGHT))
	{
		if (!ft_adjust_movement_for_wall(game, &new_pos[0], &new_pos[1], angle))
			return (false);
	}
	return (ft_change_position(game, new_pos, PLAYER_WIDTH, PLAYER_HEIGHT));
}

bool	ft_strafe(t_game *game, int key)
{
	double	new_pos[2];
	double	angle;

	angle = game->map->player->angle;
	if (key == RIGHT_KEY)
		angle += PI_2;
	else if (key == LEFT_KEY)
		angle -= PI_2;
	new_pos[0] = game->map->player->x
		+ cos(angle) * MV_STEP * game->mlx->delta_time;
	new_pos[1] = game->map->player->y
		+ sin(angle) * MV_STEP * game->mlx->delta_time;
	if (!ft_is_position_valid(game, new_pos, PLAYER_WIDTH, PLAYER_HEIGHT))
	{
		if (!ft_adjust_strafe_for_wall(game, &new_pos[0], &new_pos[1]))
			return (false);
	}
	return (ft_change_position(game, new_pos, PLAYER_WIDTH, PLAYER_HEIGHT));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:09:25 by jzaragoz          #+#    #+#             */
/*   Updated: 2024/02/26 15:12:04 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static bool	ft_adjust_movement_x(t_game *game, double *new_x,
	double *new_y, double angle)
{
	*new_x = game->map->player->x;
	*new_y = game->map->player->y + sin(angle + PI_2)
		* MV_STEP * game->mlx->delta_time;
	if (!ft_is_position_valid(game, *new_x, *new_y))
	{
		*new_y = game->map->player->y;
		return (false);
	}
	return (true);
}

static bool	ft_adjust_movement_y(t_game *game, double *new_x,
	double *new_y, double angle)
{
	*new_y = game->map->player->y;
	*new_x = game->map->player->x + cos(angle + PI_2)
		* MV_STEP * game->mlx->delta_time;
	if (!ft_is_position_valid(game, *new_x, *new_y))
	{
		*new_x = game->map->player->x;
		return (false);
	}
	return (true);
}

bool	ft_adjust_movement_for_wall(t_game *game, double *new_x,
	double *new_y, double angle)
{
	if (!ft_is_position_valid(game, *new_x, game->map->player->y))
	{
		if (!ft_adjust_movement_x(game, new_x, new_y, angle))
			return (false);
	}
	else if (!ft_is_position_valid(game, game->map->player->x, *new_y))
	{
		if (!ft_adjust_movement_y(game, new_x, new_y, angle))
			return (false);
	}
	return (true);
}

bool	ft_rotate(t_game *game, int key)
{
	if (key == LEFT_ARROW_KEY)
	{
		game->map->player->angle -= ANGLE_STEP * game->mlx->delta_time;
		if (game->map->player->angle < 0)
		{
			game->map->player->angle += 2 * PI;
		}
		return (true);
	}
	else if (key == RIGHT_ARROW_KEY)
	{
		game->map->player->angle += ANGLE_STEP * game->mlx->delta_time;
		if (game->map->player->angle >= 2 * PI)
		{
			game->map->player->angle -= 2 * PI;
		}
		return (true);
	}
	return (false);
}

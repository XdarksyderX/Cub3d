/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sliding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:03:46 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/26 19:01:29 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

bool	ft_adjust_strafe_for_wall(t_game *game, double *new_x, double *new_y)
{
	double	slide_angle;

	if (!ft_is_position_valid(game, *new_x, game->map->player->y))
		*new_x = game->map->player->x;
	if (!ft_is_position_valid(game, game->map->player->x, *new_y))
		*new_y = game->map->player->y;
	if (*new_x == game->map->player->x && *new_y == game->map->player->y)
	{
		slide_angle = game->map->player->angle + (PI / 2);
		*new_x += cos(slide_angle) * MV_STEP * game->mlx->delta_time;
		*new_y += sin(slide_angle) * MV_STEP * game->mlx->delta_time;
		return (false);
	}
	return (true);
}

bool	ft_adjust_movement_x(t_game *game, double *new_x,
	double *new_y, double angle)
{
	*new_x = game->map->player->x;
	*new_y = game->map->player->y
		+ sin(angle) * MV_STEP * game->mlx->delta_time;
	if (!ft_is_position_valid(game, *new_x, *new_y))
	{
		*new_y = game->map->player->y;
		return (false);
	}
	return (true);
}

bool	ft_adjust_movement_y(t_game *game, double *new_x,
	double *new_y, double angle)
{
	*new_y = game->map->player->y;
	*new_x = game->map->player->x
		+ cos(angle) * MV_STEP * game->mlx->delta_time;
	if (!ft_is_position_valid(game, *new_x, *new_y))
	{
		*new_x = game->map->player->x;
		return (false);
	}
	return (true);
}

bool	ft_adjust_movement_for_wall(t_game *game,
	double *new_x, double *new_y, double angle)
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

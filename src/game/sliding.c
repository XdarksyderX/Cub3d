/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sliding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:03:46 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/26 15:12:07 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static bool ft_adjust_strafe_x(t_game *game, double *new_x,
	double *new_y, double angle)
{
	*new_x = game->map->player->x;
	*new_y = game->map->player->y + cos(angle)
		* MV_STEP * game->mlx->delta_time;
	if (!ft_is_position_valid(game, *new_x, *new_y))
	{
		*new_y = game->map->player->y;
		return (false);
	}
	return (true);
}

static bool	ft_adjust_strafe_y(t_game *game, double *new_x,
	double *new_y, double angle)
{
	*new_y = game->map->player->y;
	*new_x = game->map->player->x - sin(angle)
		* MV_STEP * game->mlx->delta_time;
	if (!ft_is_position_valid(game, *new_x, *new_y))
	{
		*new_x = game->map->player->x;
		return (false);
	}
	return (true);
}

bool	ft_adjust_strafe_for_wall(t_game *game, double *new_x,
	double *new_y, double angle)
{
	if (!ft_is_position_valid(game, *new_x, game->map->player->y))
	{
		if (!ft_adjust_strafe_x(game, new_x, new_y, angle))
			return (false);
	}
	else if (!ft_is_position_valid(game, game->map->player->x, *new_y))
	{
		if (!ft_adjust_strafe_y(game, new_x, new_y, angle))
			return (false);
	}
	return (true);
}

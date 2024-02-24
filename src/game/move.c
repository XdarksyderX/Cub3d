/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:25:12 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/24 23:01:16 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static bool	ft_in_limits(float x, float y, t_game *game)
{
	if (x < 0 || x >= game->map->width || y < 0 || y >= game->map->height)
		return (false);
	return (true);
}

int	ft_move_forward_backward(t_game *game, int key)
{
	float	new_x;
	float	new_y;

	if (key == UP_KEY)
	{
		new_x = game->map->player->x
			+ cos(game->map->player->angle) * MOVE_STEP;
		new_y = game->map->player->y
			+ sin(game->map->player->angle) * MOVE_STEP;
	}
	else if (key == DOWN_KEY)
	{
		new_x = game->map->player->x
			- cos(game->map->player->angle) * MOVE_STEP;
		new_y = game->map->player->y
			- sin(game->map->player->angle) * MOVE_STEP;
	}
	if (ft_in_limits(new_x, new_y, game)
		&& game->map->map[(int)new_y][(int)new_x] != '1')
	{
		game->map->player->x = new_x;
		game->map->player->y = new_y;
		return (1);
	}
	return (0);
}

int	ft_strafe(t_game *game, int key)
{
	float	angle;
	float	new_x;
	float	new_y;

	if (key == LEFT_KEY)
	{
		angle = game->map->player->angle + M_PI_2;
		new_x = game->map->player->x + cos(angle) * MOVE_STEP;
		new_y = game->map->player->y + sin(angle) * MOVE_STEP;
	}
	else if (key == RIGHT_KEY)
	{
		angle = game->map->player->angle - M_PI_2;
		new_x = game->map->player->x + cos(angle) * MOVE_STEP;
		new_y = game->map->player->y + sin(angle) * MOVE_STEP;
	}
	if (ft_in_limits(new_x, new_y, game)
		&& game->map->map[(int)new_y][(int)new_x] != '1')
	{
		game->map->player->x = new_x;
		game->map->player->y = new_y;
		return (1);
	}
	return (0);
}

int	ft_rotate(t_game *game, int key)
{
	if (key == LEFT_ARROW_KEY)
	{
		game->map->player->angle -= ANGLE_STEP;
		if (game->map->player->angle < 0)
		{
			game->map->player->angle += 2 * M_PI;
			return (1);
		}
	}
	else if (key == RIGHT_ARROW_KEY)
	{
		game->map->player->angle += ANGLE_STEP;
		if (game->map->player->angle >= 2 * M_PI)
		{
			game->map->player->angle -= 2 * M_PI;
			return (1);
		}
	}
	return (0);
}
